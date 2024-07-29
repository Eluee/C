# typedef

## 데이터 타입의 별칭 부여
typedef는 길어지는 타입에 대해서 (ex) long long int

간결하게 쓸 수 있도록 alice를 지정하는 키워드 이다.
예시는 아래와같다.
```c
    typedef 기존_타입 새_이름;
```
구체적인 코드의 사용법은 아래와 같다
```c
    typedef long long int llint
    
    llint tmp = 10000000;
```

typedef는 struct를 사용할때도 사용이 가능하다. 아래와 같은 struct가 있다고 가정하자

```c 
    struct User {
        char name[30];
        int  age;
    };

    // 인스턴스 생성시
    struct User user = {"JSH", 24};
```
이 구조체는 아래와 같이 간결하게 선언이 가능하다
```c 
    typedef struct {
        char name[30];
        int  age;
    }User;

    User user = {"JSH", 24};
```

