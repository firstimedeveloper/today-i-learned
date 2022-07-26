# From the URL to the Web page

## ip address
ip주소는 크게 public ip와 private ip로 나누어진다. private ip address는 우리 네트워크 내에서 사용하는 ip고, public ip가 우리가 잘 아는, 하나밖에 없는 ip주소이다.
```
            +-----------------------------------------+        
            |                                         |        
    PC1 +---------+                                   |        
            |     |                                   |        
            |   +--------+   +--------+   +-------+   |        
    PC2 +-------+ Switch +---+ Router +---+ Modem +-------+ ISP
            |   +--------+   +--------+   +-------+   |        
            |     |                                   |        
    PC3 +---------+                                   |        
            |                                         |        
            +-----------------------------------------+        
```

# 프로세스
1. HSTS(HTTP Strict-Transport-Security response header) 리스트 체크, 요청 처리
   - 웹사이트가 브라우저에게 HTTP 대신 HTTPS 만 사용하라고 알리는 보안 기능
1. DNS(Domain Name Server) Lookup
   - 브라우저 캐시에 있는지 확인
   - OS의 DNS cache 확인
   - Root DNS부터 조회를 하며 결과를 갖고온다
   - translate.google.com
      - root: .
      - top-level: com
      - second-level: google
      - third-level: translate
1. ARP (Address Resolution Protocol)를 사용하여 MAC주소로 변환
   - MAC주소란 하드웨어 자체에 부여된 고유식별번호
   - ip 주소는 기기의 고유값이 아닌 유동적인 값
1. 서버와 TCP socket 연결
   - 웹페이지에 대한 정보를 받기 전, 서버와 클라이언트 사이의 논리적인 접속을 establish하기 위해 three way tls handshake를 사용함.
   - TLS (Transport Layer Security)는 안전한 인터넷 통신을 위한 암호화 프로토콜이다.
   - HTTP를 위한 SSL (Secure Sockets Layer)을 대체하는 프로토콜.
      - client -> Server: TCP SYN
      - client <- Server: TCP SYN ACK
      - client -> Server: TCP ACK
   - https 같은 경우는 TLS Handshake를 추가로 함


### Reference
- https://superuser.com/questions/935581/external-ip-addresses-subnet-masks-and-ssh-how-does-it-all-wor
- https://github.com/alex/what-happens-when/blob/master/README.rst#check-hsts-list
- https://juunone.netlify.app/web/browser-search/
- [ssl/tls] https://www.cloudflare.com/learning/ssl/what-is-ssl/
- [http] https://www.cloudflare.com/learning/ssl/what-is-https/
- [tcp] https://mindnet.tistory.com/entry/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-%EC%89%BD%EA%B2%8C-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-22%ED%8E%B8-TCP-3-WayHandshake-4-WayHandshake
- 
