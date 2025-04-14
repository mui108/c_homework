#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_LEN 100

typedef struct {
    char name[30];
    char birth[9]; // YYYYMMDD
    char gender;
    char email[50];
    char nationality[30];
    float bmi;
    char main_skill[30];
    char sub_skill[30];
    int topik; // 0 = 원어민, else = level
    char mbti[5];
    char intro[MAX_LEN];
} Candidate;

void print_line() {
    printf("---------------------------------------------------------------------------------------------\n");
}

void print_candidate(const Candidate* c) {
    printf("%-6s |%-8s | %-2s | %-18s |%-4s | %4.1f | %-6s | %-7s | %-6s | %-4s |\n",
           c->name,
           c->birth,
           (c->gender == 'F' || c->gender == 'f') ? "여" : "남",
           c->email,
           c->nationality,
           c->bmi,
           c->main_skill,
           c->sub_skill,
           (c->topik == 0) ? "원어민" : "Level",
           c->mbti);
    print_line();
    printf("%s\n", c->intro);
    print_line();
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int count = 0;

    printf("####################################\n");
    printf("     오디션 후보자 데이터 입력\n");
    printf("####################################\n");

    printf("첫 번째 후보자의 정보를 입력합니다.\n");
    printf("---------------------------------\n");

    printf("1. 성명: ");
    fgets(candidates[count].name, sizeof(candidates[count].name), stdin);
    candidates[count].name[strcspn(candidates[count].name, "\n")] = '\0';

    printf("2. 생일(YYYY/MM/DD 형식): ");
    char temp_birth[11];
    fgets(temp_birth, sizeof(temp_birth), stdin);
    temp_birth[strcspn(temp_birth, "\n")] = '\0';
    sscanf(temp_birth, "%4c/%2c/%2c", &candidates[count].birth[0], &candidates[count].birth[4], &candidates[count].birth[6]);
    candidates[count].birth[8] = '\0';

    printf("3. 성별(F/M): ");
    scanf(" %c", &candidates[count].gender);
    getchar();

    printf("4. 메일 주소: ");
    fgets(candidates[count].email, sizeof(candidates[count].email), stdin);
    candidates[count].email[strcspn(candidates[count].email, "\n")] = '\0';

    printf("5. 국적: ");
    fgets(candidates[count].nationality, sizeof(candidates[count].nationality), stdin);
    candidates[count].nationality[strcspn(candidates[count].nationality, "\n")] = '\0';

    printf("6. BMI: ");
    scanf("%f", &candidates[count].bmi);
    getchar();

    printf("7. 주 스킬: ");
    fgets(candidates[count].main_skill, sizeof(candidates[count].main_skill), stdin);
    candidates[count].main_skill[strcspn(candidates[count].main_skill, "\n")] = '\0';

    printf("8. 보조 스킬: ");
    fgets(candidates[count].sub_skill, sizeof(candidates[count].sub_skill), stdin);
    candidates[count].sub_skill[strcspn(candidates[count].sub_skill, "\n")] = '\0';

    printf("9. 한국어 등급(TOPIK, 원어민이면 0): ");
    scanf("%d", &candidates[count].topik);
    getchar();

    printf("10. MBTI: ");
    fgets(candidates[count].mbti, sizeof(candidates[count].mbti), stdin);
    candidates[count].mbti[strcspn(candidates[count].mbti, "\n")] = '\0';

    printf("11. 소개: ");
    fgets(candidates[count].intro, sizeof(candidates[count].intro), stdin);
    candidates[count].intro[strcspn(candidates[count].intro, "\n")] = '\0';

    count++;

    // 출력 화면
    printf("\n####################################\n");
    printf("     오디션 후보자 데이터 조회 \n");
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
    printf("=============================================================================================\n");
    print_candidate(&candidates[0]);
    printf("............................................ (이하 생략)...........................\n");

    return 0;
}
