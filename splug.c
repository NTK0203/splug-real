#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registration();
void login();

int logining=0;
char onID[100];

typedef struct user 
{
    char userid[100];
    char userpw[100];
    char username[100];
    struct user* next;
} user;

int main()
{
    while(1)
    {
        int menu=0;

        user* head = malloc(sizeof(user));
        head->next = NULL;
        FILE *fp;
        fp = fopen("id.txt", "rb");
        while(feof(fp) != 0)
        {
            char id[100], pw[100], name[100];
            user* _user = malloc(sizeof(user));
            _user->next = head->next;
            fscanf(fp, "%s %s %s", id, pw, name);
            strcpy(_user -> userid, id);
            strcpy(_user -> userpw, pw);
            strcpy(_user -> username, name);
            head->next = _user;
        }
        fclose(fp);
        if(logining==1)
        {
            printf("안녕하세요! %s님!\n", onID);
        }
        printf("==메뉴==\n1. 회원가입\n2. 로그인\n3. 로그아웃\n4.영어 단어 맞추기\n5. 회원 탈퇴\n6. 프로그램 종료\n:");
        scanf("%d",&menu);
        if(menu==1)
        {
            if(logining==1)
            {
                printf("이미 로그인 중 입니다. 초기 화면으로 돌아갑니다.");
            }
            else
            {
                registration(head);
            }
        }
        else if(menu==2)
        {
            if(logining==1)
            {
                printf("이미 로그인 중 입니다. 초기 화면으로 돌아갑니다.");
            }
            else
                login(head);
        }
        else if(menu==3)
        {
            
        }
        else if(menu==4)
        {
            
        }
        else if(menu==5)
        {
            
        }
        else if(menu==6)
        {
            printf("다음에 또 만나요!!\n");
            break;
        }
        else
        {
            printf("메뉴는 1~6까지 숫자로 입력해주세요.\n");
            getchar();
        }
    }
    return 0;
}

void registration(user* target)
{
    char r_id[100], r_pw[100], r_name[100];
    printf("<회원가입>\n");
    while(1)
    {
        int reset=0;
        printf("아아디 : ");
        scanf("%s", r_id);
        user* temp = target->next;
        while(temp != NULL)
        {
            if(strcmp(temp->userid, r_id)==0)
            {
                printf("중복된 아이디입니다. 다시 입력하세요.\n");
                reset=1;
                break;
            }
            temp = temp->next;
        }
        if (reset==0)
        {
            break;
        }
    }
        printf("사용 가능한 아이디입니다.\n비밀번호 : ");
        scanf("%s",r_pw);
        printf("이름: ");
        scanf("%s",r_name);

        FILE *fp;
        fp=fopen("id.txt", "ab");
        fprintf(fp, "%s %s %s\n", r_id, r_pw, r_name);
        fclose(fp);
    
    printf("회원가입이 완료되었습니다.\n");
}

void login(user* target)
{
    int conform=0;
    char loginid[100], loginpw[100];
    while(1)
    {
        printf("<로그인>\n아이디: ");
        scanf("%s",loginid);
        printf("비밀번호: ");
        scanf("%s",loginpw);
        user* temp = target->next;
        while(temp != NULL)
        {
            if(strcmp(temp->userid, loginid)==0)
            {
                if(strcmp(temp->userpw, loginpw)==0)
                {
                    conform=1;
                    break;
                }
            }
            temp = temp->next;
        }
        printf("잘못된 아이디 혹은 비밀번호 입니다. 다시 입력해주세요.\n");
    }
    if (conform==1)
    {
        printf("로그인 성공!\n");
        logining=1;
        strcpy(onID,loginid);
    }
}