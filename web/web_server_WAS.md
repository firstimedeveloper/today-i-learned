# Web, WAS의 의미와 차이




## python 예시

터미널 창에 `python -m 'SimpleHTTPServer` 을 실행하면 말 그대로 간단한 HTTP 서버가 `localhost:8000`에 작동이 되고, 브라우저에 이를 입력하면 아래와 같은 화면을 볼 수 있다. 사진을 보면, 내 컴퓨터 내의 각종 (정적) 파일들을 열고 볼 수 있다.

이것이 웹서버이다. HTTP 프로토콜 기반으로 클라이언트(브라우저)로부터 요청을 받고, 컴퓨터 내의 정적 콘텐츠를 클라이언트에게 제공하는 프로그램이다.

WAS - Web Application Server
``` python
@app.route('/')
def homepage():
    return '<html>My homepage</html>'

@app.route('/about')
def about():
    return '<html>My name is John</html>'
```



위 코드는 pthon web framework인 flask 코드의 일부분이다. 위 코드를 보게되면, 클라이언트로부터 url을 입력받고, 각각 다른 함수를 호출한다. 위의 예시는 굉장히 간단한 html 코드를 리턴하지만, 기능적으로는 클라이언트의 request에 따는 정적인 콘텐츠를 제공할 수 있다.







## 웹서버

### 의미 -

- 소프트웨어 - 웹 브라우저 클라이언트로부터 HTTP 요청을 받아 html css jpeg등의 정적 컨텐츠를 클라이언트에게 제공하는 프로그램

- 하드웨어 - 위 프로그램이 설치되어있는 컴퓨터

### 기능 - 

HTTP 프로토콜을 기반으로 하여 클라이언트의 요청을 서비스 하는 기능을 담당한다.
요청에 따라 아래의 두 가지 기능 중 적절하게 선택하여 수행한다.

#### 기능 1)

- 정적인 컨텐츠 제공

- WAS를 거치지 않고 바로 자원을 제공한다.

#### 기능 2)

- 동적인 컨텐츠 제공을 위한 요청 전달

- 클라이언트의 요청(Request)을 WAS에 보내고, WAS가 처리한 결과를 클라이언트에게 전달(응답, Response)한다.

- 클라이언트는 일반적으로 웹 브라우저를 의미한다.

### Web Server의 예

- Ex) Apache Server, Nginx, IIS(Windows 전용 Web 서버) 

- IIS는 기본적으로 웹서버의 기능이 메인이지만, .NET runtime environment과 함께 사용되면서 WAS와 같은 기능도 같이 수행할 수 있다.

## 웹 어플리케이션 서버

### 의미 - 

- 앞서 말한 정적인 컨텐츠가 아닌 DB CRUD 등 비즈니스 로직을 처리하기 위해 만들어진 서버
- Web Server는 주로 HTTP 기반이지만 WAS는 HTTP외의 프로토콜을 핸들할 수 있다.
- 특히 흔히 사용되는 자바 기반의 WAS 같은 경우, JSP(JavaServer Pages, HTML 코드에 Java 코드를 넣어 동적 웹페이지를 생성할 수 있게 하는 도구)와
Servlet(웹 프로토콜을 처리할 수 있고, HTML코드를 동적으로 생성 가능) 와 같은 툴을 사용할 수 있게 하는 환경을 제공한다
- 웹 컨테이너(Web Container) 또는 서블릿 컨테이너(Servlet Container)라고도 불린다.

### WAS의 역할 -

- 분산 트랜잭션, 보안, 메시징, 쓰레드 처리 등의 기능을 처리하는 분산 환경에서 사용된다.
- 주로 DB 서버와 같이 수행된다.
- WAS = Web Server + Web Container
- Web Server 기능들을 구조적으로 분리하여 처리하고자하는 목적으로 제시되었다.
- 현재는 WAS가 가지고 있는 Web Server도 정적인 컨텐츠를 처리하는 데 있어서 성능상 큰 차이가 없다.

### WAS의 주요 기능
- 프로그램 실행 환경과 DB 접속 기능 제공
- 여러 개의 트랜잭션(논리적인 작업 단위) 관리 기능
- 업무를 처리하는 비즈니스 로직 수행

### WAS의 예
- Ex) Oracle Weblogic, Tomcat, JBoss (지금은 Wildfly), Jeus, Web Sphere 등.
- 기본적으로 WAS는 Java 기반이다

#### 참고

https://gmlwjd9405.github.io/2018/10/27/webserver-vs-was.html
https://stackoverflow.com/questions/936197/what-is-the-difference-between-application-server-and-web-server
[Gunicorn]Gunicorn 란? 쓰는 이유는? — Leffe's tistory

**정리 - 이 두가지에 차이를 두는 이유는, 기능을 분리하여 부하를 줄이고, 사용자에 더짧은 로딩타임을 제공하고, 여러대의 WAS를 연결함으로써 로드 밸런싱 과 서버 하나 에 오류가 나도 사용자 입장에서 인지를 못하게끔 하는데에 있다.**
