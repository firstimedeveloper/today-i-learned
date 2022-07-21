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
1. HSTS 리스트 체크
2. DNS Lookup
    3. 브라우저 캐시에 있는지 확인
4. ARP
5. TLS Handshake


### Reference
- https://superuser.com/questions/935581/external-ip-addresses-subnet-masks-and-ssh-how-does-it-all-wor
