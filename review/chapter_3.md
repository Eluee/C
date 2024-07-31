# 문자열
문자열은 배열과 유사한 형태를 띄고 있습니다.
문자를 저장하는 자료형인 char은 기본적으로 한 변수에 한 글자를 넣을 수 있습니다. 그래서 문자열은 문자의 길이에 따라 그 크기가 달라질 수 있습니다.
아래와 같은 코드가 있습니다.
```c
char c = 'A';
char str[5] = "Hello"
```
c는 단일문자를 담은 변수이며
str은 문자열을 담는 배열이다.
여기서 알아야할점은 문자열은 끝에 문자의 끝을 표시하는 널값이 들어간다.
그래서 문자열을 선언할때 기본 문자열보다 길이를 하나더 늘려서 선언해준다.

**포인터를 사용한 문자열**
포인터를 사용하여 여러 문자열을 한번에 사용 할 수 있는 방법도 존재한다.
예시코드이다.
```c
// str의 각 요소에는 각 문자열의 첫글자의 주소값이 들어간다.
char *str[] = {"Hello", "World", "JSH", "apple" };
```
# 구조체, 공용체, 열거형

### 구조체 선언 및 초기화

구조체는 다양한 자료형의 변수를 하나의 사용자 정의 데이터 타입으로 묶어주는 역할을 합니다.

### 기본 구조체 선언

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float score;
} Student;

int main() {
    Student student1 = {1, "John Doe", 85.5};

    printf("ID: %d\n", student1.id);
    printf("Name: %s\n", student1.name);
    printf("Score: %.2f\n", student1.score);

    return 0;
}
```

- **구조체 정의**: `typedef struct`를 사용하여 구조체를 정의합니다.
  - `int id;` - 정수형 멤버 변수
  - `char name[50];` - 문자열을 저장할 배열형 멤버 변수
  - `float score;` - 실수형 멤버 변수

- **구조체 초기화**: 구조체를 선언할 때 값을 초기화할 수 있습니다.

### 구조체의 멤버 접근

- 구조체의 멤버에 접근할 때는 `.` 연산자를 사용합니다. 예를 들어, `student1.id`는 `student1` 구조체의 `id` 멤버를 의미합니다.

## 공용체 (Union)

### 공용체 선언 및 초기화

공용체는 여러 자료형의 변수를 하나의 메모리 공간에서 공유하는 데이터 타입입니다. 공용체의 크기는 가장 큰 멤버의 크기와 같습니다.

### 기본 공용체 선언

```c
#include <stdio.h>

typedef union {
    int intValue;
    float floatValue;
    char strValue[20];
} Data;

int main() {
    Data data;

    data.intValue = 10;
    printf("Int: %d\n", data.intValue);

    data.floatValue = 5.6;
    printf("Float: %.1f\n", data.floatValue);

    snprintf(data.strValue, sizeof(data.strValue), "Hello");
    printf("String: %s\n", data.strValue);

    return 0;
}
```

- **공용체 정의**: `typedef union`을 사용하여 공용체를 정의합니다.
  - `int intValue;` - 정수형 멤버
  - `float floatValue;` - 실수형 멤버
  - `char strValue[20];` - 문자열 배열 멤버

- **공용체의 멤버 접근**: 공용체의 모든 멤버가 같은 메모리 공간을 공유하므로, 마지막에 저장된 값만 유효합니다. 공용체의 멤버에 접근할 때는 `.` 연산자를 사용합니다.

## 열거형 (Enumeration)

### 열거형 선언 및 사용

열거형은 상수 집합에 이름을 부여하여 코드의 가독성을 높이는 데 사용됩니다.

### 기본 열거형 선언

```c
#include <stdio.h>

typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

int main() {
    Color myColor = GREEN;

    switch (myColor) {
        case RED:
            printf("Color is Red\n");
            break;
        case GREEN:
            printf("Color is Green\n");
            break;
        case BLUE:
            printf("Color is Blue\n");
            break;
        default:
            printf("Unknown Color\n");
            break;
    }

    return 0;
}
```

- **열거형 정의**: `typedef enum`을 사용하여 열거형을 정의합니다.
  - `RED`, `GREEN`, `BLUE`는 열거형의 값입니다.
  - 기본적으로 첫 번째 값은 0부터 시작하며, 이후 값은 1씩 증가합니다.

- **열거형 사용**: 열거형 값에 따라 조건문을 작성하여 코드의 가독성을 높일 수 있습니다. 열거형 값은 `switch` 문과 같은 조건문에서 유용하게 사용됩니다.

### 열거형과 상수

- **기본값**: 열거형 값은 기본적으로 0부터 시작하며, 정의된 순서에 따라 증가합니다.
- **사용자 정의 값**: 특정 값을 할당할 수도 있습니다. 예를 들어, `typedef enum { RED = 1, GREEN = 2, BLUE = 4 } Color;`와 같이 정의할 수 있습니다.
