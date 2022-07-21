# Redis

"The open source, in-memory data store used by millions of developers as a database, cache, streaming engine, and message broker."

Redis는 많은 자료구조의 데이터를 지원하는 인메모리 key-value 저장소이다.

Redis가 주로 사용이되는 케이스는:
- Message Queue
- Shared Memory
- Session Cache
- Full page Cache
- Leaderboards

Remote Dictionary Server의 줄임말. 2009년에 Salvatore Sanfilippo가 자신의 real-time log analyzer 스타트업의 scalability를 개선하기 위해서 시작한 프로젝트이다. 일반적인 DBMS를 사용하면서 맞닥뜨린 scaling 관련 문제를 풀기 위해서 시작했다.
Redis는 store과 cache 두 작업 모두 수행할 수 있는 시스템의 선두자이다. 이를 위해서 Redis 내의 데이터는 컴퓨터의 메인 메모리에 위치하여 많은 양의 데이터 읽기/쓰기를 가능케한다. 컴퓨터 하드드라이브와 같은 persistant disk에 저장이 되기도 하는데, 이는 시스템이 다시 실행시켰을때 데이터를 메모리에 다시 불러오기 위해 사용이 된다. 여타 RDBMS와 다르게 유저는 query를 하지 않고, 각 데이터타입에 맞는 작업들을 수행 할 수 있는 코맨드들을 실행한다.
    
## 다양한 자료구조를 저장할 수 있다.
- string
- list of strings
- sorted sets of strings
- hash table (key, value: string)


## Persistence (영속성)
데이터베이스시스템에게 있어서 시스템이 어떠한 이유로 인해 갑자기 중단이되어도 다시 동일한 데이터를 액세스 할 수 있도록하는 영속성은 굉장히 중요한 요소이다. Redis에서는 이 영속성을 2가지 방법으로 수행한다.
1. Snapshotting (스냅샷)
    - 비동기적으로 메모리에 위치한 데이터셋이 비동기적으로 규칙적인 인터벌로 binary dump의 형태로 디스크에 보내진다. (Redis RDB Dump file format)
3. Journaling 
    - 데이터셋을 변경하는 오퍼레이션들을 append-only file에 추가한다. 이는 백그라운드에서 진행이되며 보통 스냅샷보다 더 안전한 방법으로 간주된다.

기본적으로 Redis에서는 파일시스템에 2초 간격으로 저장이되고 이에 대한 추가 옵션은 사용자가 지정할 수 있다. 이 기본 셋팅이 적용된 상태에서 System failure의 상황에는 몇초간의 데이터로스가 생길 수 있다.

## Replication

## Performance
일반적으로 RDBMS 시스템은 모든 transaction이 이루어지기 전에 디스크 쓰기 작업을 거치고 이는 굉장히 느리다.
