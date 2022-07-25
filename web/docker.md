# docker

## 도커의 정의

도커는 오픈소스화 된 플랫폼으로, 애플리케이션을 개발, 배포, 실행하는데 도움을 준다. 도커는 애플리케이션을 개발하는 환경과 프로덕션 환경의 차이에 따른 어려움들을 해소시킬 수 있을 뿐더러, 애플리케이션을 여러번 배포할 때에도 매번 동일하게 실행시키는 것이 가능하다.

일반적으로 소프트웨어 개발을 할때 애플리케이션별로 굉장히 많은 시스템, third-party 라이브러리, 프래임워크를 사용하게 된다. 이 소프트웨어들

도커는 컨테이너라는 추상화된 개념을 사용하고, 도커에서의 기본 실행 단위는 이 컨테이너이다. 컨테이너 안에는 해당 애플리케이션이 실행이 되기 위해서 필요한 것들이 다 있기 때문에, 이 컨테이너의 호스트, 즉, 사용자의 OS와 설치된 툴 등의 개발환경은 전혀 영향이 없다. 이 컨테이너는 쉽게 공유가 가능하고, 다른 사람의 개발환경에서도 동일하게 실행한다.

![docker-structure](/images/docker-structure.png)

## 도커의 기본 개념
![docker-architecture](/images/docker-architecture.png)
### 도커 데몬 Docker Daemon
`dockerd`는 도커의 api request를 처리하고 이미지, 컨테이너, 네트워크, 볼륨과 같은 docker objects를 관리한다. 다른 docker daemon과 커뮤니케이트 또한 가능하다.

### 도커 클라이언트 Docker Client
`docker`를 사용하여, 유저들이 도커를 사용할 수 있게 한다. `docker run`과 같은 코맨드를 실행하게 되면, docker client가 dockerd에 보내게 된다. 하나의 클라이언트는 하나 이상의 도커 데몬과 연결이 가능하다.

### 도커 데스크탑 Docker Desktop
사용자의 컴퓨터에 설치할 수 있는 프로그램으로, 앞서 설명한 docker daemon, docker client를 더불어, docker compose, docker content trust kubernetes, credential helper도 포함되어, 더 손 쉽게 도커를 설치 및 관리 할 수 있다.

### 도커 레지스트리 Docker Registry
도커 레지스트리는 도커 이미지 저장소이다. 도커 레지스트리는 public, private로 나누어 있는데, 이중 Docker Hub는 github과 비슷한 역할의 퍼블릭 레지스트리로 다른사용자들이 배포한 이미지 등을 검색하고 사용할 수 있다.

### 도커 오브젝트 Docker Objects

#### 이미지 Images
이미지는 도커 컨테이너를 만들수 있는 명령이 담긴 read-only template이다. 실제 프로덕션환겨에서는 이미지 내에 또다른 이미지들이 포함되어 있다. 예컨데, ubuntu 이미지 위에 아파치 웹서버를 설치하고 configure하는 새로운 이미지를 만들 수 있다. 사용자의 입장에서는 도커 허브에 올라온 무수히 많은 이미지들을 끌어다 사용할 수 있고, 새로운 이미지를 만들 수 있다. 
이미지는 도커파일(Dockerfile)이라는 configuration file로 만든다. Dockerfile 내에는 애플리케이션을 설치하는 간단한 명령문이 포함되어 있고 해당 명령문은 도커 이미지의 layer에 해당이 된다. 이 layer라는 개념이 도커의 또다른 장점으로 꼽히는 이유는, 이미지를 다시 생성을 하게 될때, 처음부터 끝까지 다시만드는 것이 아니라, 바뀐 layer만 변경하여 이미지를 재생성을 할 수 있기 때문에, 도커의 이미지는 타 virtualization 기술보다 작고 빠르다.

#### 컨테이너
컨테이너는 runnable instance of an image이다. 이미지가 컨테이너를 실행할 수 있는 명령문에 해당이 된다면, 컨테이너는 만들어진 이미지에 해당이된다. 컨테이너는 기본적으로 다른 컨테이너, 호스트 머신과 분리가 되어있고, 네트워크, 스토리지 등을 사용할 수 있도록 추가적인 관리가 가능하다. 따로 persistent storage에 저장을 하지 않는다면 도커에서 달라진 state는 container를 지우게되면 사라진다.




