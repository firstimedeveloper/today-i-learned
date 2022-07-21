# Apache와 Nginx

Apache와 Nginx 둘다 웹서버이다.
##history and market share	
### Apache	
1995년도에 처음 릴리스 되면서 시장을 장악 함.

Apache Foundation에서 개발 및 유지되고 있음.

주요 리눅스 distribution에 pre-installed되어서 나오는 탓에 아직 시장 점유율이 상당함.

지금도 Nginx와 더불어 가장 많이 사용이 되는 웹서버이지만, 계속 밀려나고 있음.

### Nginx
2004년에 Igor Sysoev이라는 러시아 개발자가 처음 배포한 뒤 오픈소스로 유지/관리되고 있으나 Nginx Plus라는 enterprise용 티어도 있음.

2019년도에 F5에 인수됨.

후발주자이지만 서서히 아파치의 시장 점유율을 뺏고 1위자리에 오름.

특히 글로벌 탑 웹사이트를 보면 Nginx 사용자가 더 많은 것을 볼 수 있음.


## 기능	
### Apache	

process-driven architecture

하나의 connection request를 처리하기 위해 single thread를 만든다. 단점으로, 많은 트래픽을 받게 되면 로딩타임이 상당히 길어질 수 있고, 심하면 서버가 터질 수 있다.

이를 해결하기 위해서 MPM(multi-processing modules)을 제공하기 때문에 상황에 따라서 알맞은 방법(mpm_prefork, mpm_worker, mpm_event)을 사용하면 된다.

### Nginx
asynchronous event-driven architecture

하나의 프로세스로 많은 connection을 처리한다.

마스터 프로세스가 port binding, reading/evaluating configuration files와 같은 모든 privileged 액션을 처리하고, 자식 프로세스를 생성한다.

3가지 자식 프로세스가 있다: Cache loader process, cache manager process, worker process

worker process 안에는 더 작은 단위의 worker connections가 있고, 이 worker connection들이 하나의 request thread를 처리한다. Worker process는 굉장히 많은 양의 http connection을 효율적으로 처리할 수 있다.


## configuration	
### Apache	

.htaccess

위 확장자를 따르는 configuration 파일을 사용함.

새로운 http request가 올때 아파치가 handle을 하는 방식을 관리할 수 있도록, 굉장히 많은 기능과 flexibility를 제공함.

Some examples are: different redirection rules, maximum upload file sizes, URL rewrites, memory limits, directory protection (htpasswd), expires headers, cache-control headers, encoding headers, cookies, query string manipulations. 

장점 중 하나로 꼽히는 기능은 - 이 configuration file은 서버의 루트를 더불어 다른 하위 디렉토리에도 하나씩 사용할 수 있음.

GCP, AWS와 같은 shared hosting provider에게는 하나의 서버에 많은 서버 사용자를 수용할 수 있음.

단점 - 

각 디렉토리마다 .htaccess 파일이 있을 수 있기 때문에, 매 request마다 .htaccess를 찾을때까지 해당 tree를 traverse 해야함. 심지어, .htaccess를 사용하지 않아도, 허용이 되어있으면 확인을 해주어야하기 때문에, 속도가 상당히 느려짐.

루트 액세스가 없는 사용자에게 server configuration을 바꾸는 것을 허용하게 되면 보안에 문제가 생길 수 있음.


### Nginx


	Configuration 시스템이 없는 탓에 아파치보다 더 효율적이고 빠름.
Modules (사용자가 웹서버의 기능적인 부분을 확장을 할 수 있게 하는 툴)	

dynamic modules system, 동적인 모튤 시스템이 있음.

매 request 단위로 .htaccess를 확인하기때문에 

웹서버가 가동이 된 후에도 모듈을 설치, (비)활성화시킬 수 있다.

encryption, logging, redirection, editing requests and responses with advanced sytax등이 있다.

	

not dynamically loadable

nginx 모듈은 c로 작성이 되며 컴파일을 해야한다.

nginx plus 사용자는 dynamic 모듈 기능을 사용할 수는 있다.

nginx의 모듈 시스템은 apache에 비해 flexible 하진 않지만, 오히려 보안상 더 좋을 수 있음.
