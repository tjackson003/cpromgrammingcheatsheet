#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* THE FOLLOWING IS THE FUNCTION THAT WILL BE CALL INSIDE THE MAIN FUNCTION. IT'S ALWAYS GOOD PRACTICE TO DEFINE FUNCTIONS THAT WILL BE CALLED IN THE MAIN FUNCTION BEFORE THE MAIN FUNCTION. THE VARIABLES INSIDE THE PARENTHESIS ARE CALL PARAMETERS. */

void sayHi(char name[], int userYears) {
    printf("Hello %s. This is the sayHi function. You are %d years old?\n", name, userYears);
} /* THIS PARTICULAR FUNCTION IS 'VOID' AND THUS DOES NOT RETURN ANYTHING. */

double cube(double thisNum) {
    return thisNum * thisNum * thisNum; /* THIS IS THE SIMPLER VERSION OF THE COMMENTED OUT CODE BELOW. */
    // double result = thisNum * thisNum * thisNum;
    // return result;
} /* THIS IS THE EXAMPLE FUNCTION THAT GETS CALLED IN THE RETURN STATEMENT SECTION. YOU COULD ALSO PUT THIS FUNCTION AFTER THE MAIN FUNCTION AND LEAVE A PROTOTYPE 'double cube(doube thisNum)' UP HERE. */

int max(int maxNum1, int maxNum2) {
    int maxResult;
    if(maxNum1 > maxNum2) {
        maxResult = maxNum1;
    } else {
        maxResult = maxNum2;
    }
    return maxResult;
} /* BASIC FUNCTION USING AN IF STATMENT. */

int maxThree(int maxNum1, int maxNum2, int maxNum3) {
    int maxResult;
    if(maxNum1 > maxNum2 && maxNum1 > maxNum3) {
        maxResult = maxNum1;
    } else if(maxNum2 > maxNum1 && maxNum2 > maxNum3) {
        maxResult = maxNum2;
    } else {
        maxResult = maxNum3;
    }
    return maxResult;
} /* SLIGHTLY LESS BASIC FUNCTION USING AN IF STATEMENT. */

struct Student {
    char stuName[50];
    char major[50];
    int studentAge;
    double stuGPA;
}; /* STRUCTS SEEM A LOT LIKE OBJECTS IN MOST OTHER PROGRAMMING LANGUAGES. */

int main()
{
    /********** HELLO, WORLD **********/

    printf("Hello, World!\n");

    /********** MAKING A TRIANGLE **********/

    printf("Hello, World!\n");
    printf("    /|\n");
    printf("   / |\n");
    printf("  /  |\n");
    printf(" /___|\n");
    printf("Look, a triangle!\n");

    /********** VARIABLES AND HOW THEY CAN BE USED **********/

    int age = 24;
    double myAge = 24.6;
    float tjAge = 24.65;
    char firstLetter = 'T'; /* WITH THE 'char' DATA TYPE, YOU CAN LITERALLY ONLY PLACE ONE CHARACTER IN THE VARIABLE. YOU HAVE TO PUT IT IN SINGLE QUOTES ''. */
    char myName[] = "TJ"; /* THIS IS HOW YOU WRITE A STRING IN C. THE EMPTY BRACKETS ARE AN ARRAY IN WHICH THE CHARACTERS OF THE STRING ARE INDEXED. */

    printf("My name is %s.\n", myName);
    printf("It starts with a %c.\n", firstLetter);
    printf("I am %d years old.\n", age);
    printf("Well, actually, I'm about %lf years old.\n", myAge);
    printf("To get even more specific, I'm %f years old.\n", tjAge);

    printf("My name is %s and I'm %d years old.\n", myName, age); /* EXAMPLE USING TWO OR MORE VARIABLES IN THE SAME PRINTF FUNCTION. THE VARIABLES HAVE TO BE PLACED IN ORDER OF OCCURRENCE AFTER THE PRINTF STATEMENT. */

    /********** SOME THINGS WE CAN DO WITH MATH IN C. DON'T FORGET #INCLUDE <MATH.H> TO HAVE ACCESS TO SOME OF THESE MATHEMATIC FUNCTIONS. **********/

    float testNum = 2.5 / 6.3;

    printf("%f\n", testNum);
    printf("%d\n", 6 + 3);
    printf("%d\n", 6 - 3);
    printf("%d\n", 6 * 3);
    printf("%d\n", 6 / 3);

    printf("%f\n", pow(4, 3)); /* POWER OF/EXPONENTS */
    printf("%f\n", sqrt(144)); /* SQUARE ROOT */
    printf("%f\n", ceil(36.356)); /* CEILING/ROUND UP */
    printf("%f\n", floor(36.356)); /* FLOOR/ROUND DOWN */

    /********** COMMENTS. THIS. THIS IS LITERALLY A COMMENT. LOL **********/

    /********** CONSTANTS **********/

    int num = 5; /* VARIABLE NUM STARTS AS 5 */
    printf("%d\n", num); // 5
    num = 8; /* WE CHANGE IT TO 8 */
    printf("%d\n", num); // 8

    const int CONSTNUM = 10; /* THIS IS A CONSTANT VARIABLE. ONCE SET IT CANNOT BE CHANGED UNLESS THE 'const' IS TAKEN AWAY FROM THE VARIABLE. GIVING CONSTANTS ALL CAPITAL LETTER NAMES ISN'T REQUIRED BUT HELPS DISTINGUISH THEM FROM OTHER VARIABLES. */
    printf("%d\n", CONSTNUM);

    printf("Hello\n"); // ALSO CONSIDERED A CONSTANT. STRING LITERAL I THINK?
    printf("%d\n", 70); // SAME AS ABOVE

    /********** GETTING USER INPUT **********/

    int userAge; /* DECLARES A VARIABLE TO HOLD THE USER'S AGE ONCE THEY PUT IT IN. */
    printf("Enter your age: ");
    scanf("%d", &userAge); /* ALLOWS THE USER TO ENTER IN INFO; IN THIS CASE, THEIR AGE. THE '&' SYMBOL IS A POINTER. IT IS NEEDED. */
    printf("You are %d years old. Congrats!\n", userAge); /* PRINTS OUT "YOU ARE [USERAGE] YEARS OLD. CONGRATS!" */

    double gpa; /* BASICALLY THE SAME AS ABOVE, BUT WITH A DOUBLE/FLOAT NUMBER. */
    printf("What's your GPA: ");
    scanf("%lf", &gpa);
    printf("Damn, %lf? That's pretty solid, dude!\n", gpa);

    char mark; /* NOW WITH CHARACTERS. FOR SOME REASON THIS DOESN'T RIGHT WHEN THE TWO USER INPUT PROMPTS ABOVE ARE ACTIVE. WORK ON THIS BUG LATER, BUT FOR NOW, JUST COMMENT THE ABOVE PROMPTS OUT TO GET THIS ONE TO FUNCTION PROPERLY. */
    printf("What grade did you get: ");
    scanf(" %c", &mark); /* ADD A SPACE BEFORE %c. "THE BLANK IN THE FORMAT STRING TELLS 'scanf' TO SKIP LEADING WHITESPACE AND THE FIRST NON-WHITESPACE CHARACTER WILL BE READ WITH THE '%c' CONVERSION SPECIFIER." THIS IS A SPECIAL SOLUTION TO THE PROBLEM THAT I FOUND ON STACKOVERFLOW. ALSO, A LOT OF PEOPLE ON STACKOVERFLOW SAY NOT TO EVEN USE 'scanf' WHEN GETTING USER PROMPTS. LOOK INTO LATER. */
    printf("Wow, %c is absolutely amazing.\n", mark);

    char str[20]; /* PROBABLY GONNA HAVE SAME ISSUES AS THE PROMPT ABOVE. A NUMBER IS IN THE BRACKETS TO TELL C HOW MANY CHARACTERS TO LIMIT THE USER'S ANSWER TO. */
    printf("Enter your name: ");
    scanf("%s", str); /* YOU DON'T HAVE TO PUT A '&' BEFORE THE VARIABLE IN THIS ONE BECAUSE THE STRING IS ACTUALLY AN ARRAY SO YOU WANT TO WHOLE THING. */
    printf("%s is a cool name!\n", str);

    /* TURNS OUT THE PROBLEM WITH 'scanf' IS THAT (ESPECIALLY IF YOU'RE TRYING TO CAPTURE A STRING) 'scanf' STOPS AFTER THE FIRST SPACE IT SEES. SO, FOR EXAMPLE, IF YOU WERE TRYING TO CAPTURE AN INPUT OF 'JOHN SMITH', IT WOULD ONLY CAPTURE 'JOHN' BECAUSE IT WOULD STOP ONCE IT HITS THE SPACE BETWEEN 'JOHN' AND 'SMITH'. SO THE APPARENT SOLUTION FOR THIS IS 'fgets()'. */

    /* CORRECTION: 'fgets()' GETS A LINE OF TEXT FROM THE USER. */

    char another_str[20];
    printf("Enter your full name: ");
    fgetc(stdin); /* YOU HAD A BUG WITH 'fgets()' BEFORE YOU ENTERED THIS LINE. ENTER THIS LINE IN WHENEVER YOU USE 'fgets()' FROM NOW ON. */
    fgets(another_str, 20, stdin); /* GETS NAME OF VARIABLE, HOW MANY CHARACTERS, WHERE YOU WANT TO GET THE INPUT FROM. */
    printf("Your name is %s\n", another_str);

    /********** BUILDING A BASIC CALCULATOR **********/

    double num1;
    double num2;
    printf("Enter first numnber: ");
    scanf("%lf", &num1);
    printf("Enter second numnber: ");
    scanf("%lf", &num2);

    printf("Answer: %f\n", num1 + num2);

    /********** BUILDING A MAD LIBS GAME **********/

    char color[20];
    char plural_noun[20];
    char celebrityF[20];
    char celebrityL[20];

    printf("Enter a color: ");
    scanf("%s", color);
    printf("Enter a plural noun: ");
    scanf("%s", plural_noun);
    printf("Enter in a celebrity: "); /* THIS AND THE LINE BELOW WILL REQUIRE THAT YOU INPUT TWO NAMES/THINGS TO WORK. */
    scanf("%s%s", celebrityF, celebrityL);

    printf("Roses are %s\n", color);
    printf("%s are blue\n", plural_noun);
    printf("I love %s %s\n", celebrityF, celebrityL);

    /********** ARRAYS **********/

    int luckyNumbers[] = {4, 8, 15, 16, 23, 42}; /* 0 INDEXED */
                      //  0  1   2   3   4   5

    int capacityArr[10]; /* LETS C KNOW THAT THIS ARRAY SHOULD ONLY BE ABLE TO HOLD 10 ITEMS. */

    /********** FUNCTIONS **********/

    sayHi("User", 24); /* RUNS THE FUNCTION BELOW THAT IS OUTSIDE OF THE INT MAIN FUNCTION. THE THINGS IN THE PARENTHESIS ARE ARGUMENTS. THEY REPLACE THE FUNCTION'S PARAMETERS (IF THE FUNCTION HAS PARAMETERS.) */

    /********** RETURN STATEMENT **********/

    printf("Answer: %f\n", cube(3.0)); /* CALLS THE 'cube()' FUNCTION AND RETURNS "Answer: [RESULT]. */

    /********** IF STATEMENTS **********/

    printf("Max Number is: %d\n", max(12, 15)); /* CALLS THE 'max()' FUNCTION. */

    printf("Max number of these three is: %d\n", maxThree(52, 67, 19)); /* CALLS THE 'maxThree()' FUNCTION. */

    /********** BUILDING A BETTER CALCULATOR **********/

    double calcNum1;
    double calcNum2;
    char op;

    printf("Enter your first number: ");
    scanf("%lf", &calcNum1);
    printf("Enter a basic mathematic operator: ");
    scanf(" %c", &op);
    printf("Enter your second number: ");
    scanf("%lf", &calcNum2);

    if(op == '+') {
        printf("%f\n", calcNum1 + calcNum2);
    } else if(op == '-') {
        printf("%f\n", calcNum1 - calcNum2);
    } else if(op == '*') {
        printf("%f\n", calcNum1 * calcNum2);
    } else if(op == '/') {
        printf("%f\n", calcNum1 / calcNum2);
    } else {
        printf("That is not a vaild operator\n");
    }

    /********** SWITCH STATEMENTS **********/
    
    char stuGrade;

    printf("What grade did you get again? ");
    scanf(" %c", &stuGrade);

    switch(stuGrade) {
        case 'A' :
            printf("You did excellent!\n");
            break;
        case 'B' :
            printf("You did good!\n");
            break;
        case 'C' :
            printf("You did average.\n");
            break;
        case 'D' :
            printf("You didn't do so well.\n");
            break;
        case 'F' :
            printf("You failed.\n");
            break;
        default :
            printf("Invalid grade entered.\n");
    }
    
    /********** STRUCTS **********/
    
    struct Student student1; /* THIS (student1) IS BASICALLY A CONTAINER THAT WILL HOLD AND THE DATA IN THE STRUCT 'Student'. */

    student1.studentAge = 22;
    student1.stuGPA = 3.2;
    strcpy(student1.stuName, "Jim"); /* 'strcpy' ALLOWS YOU TO DO THIS WITH STRINGS. */
    strcpy(student1.major, "Business");

    printf("%s\n", student1.stuName);
    printf("%s\n", student1.major);
    printf("%f\n", student1.stuGPA);
    printf("%d\n", student1.studentAge);
    
    /********** WHILE LOOPS **********/
    
    int index = 1;

    while(index <= 5) {
        printf("%d\n", index);
        index++;
    } /* WHILE 'index' IS LESS THAN OR EQUAL TO 5, PRINT OUT 'index' AND ADD 1 TO 'index'. THE WHILE LOOP STOPS AFTER THE CONDITION FAILS TO BE MET. WATCH OUT FOR INFINITE LOOPS (WHEN THE CONDITION IS ALWAYS MET). */

    do {
        printf("%d\n", index);
        index++;
    } while(index <= 5); /* DOES WHATEVER IS IN THE 'DO' BRACKETS BEFORE CHECKING THE WHILE CONDITION. */
    
    /********** BUILDING A GUESSING GAME **********/
    
    int secretNumber = 5;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    int outOfGuesses = 0;

    while(guess != secretNumber && outOfGuesses == 0) {
        if(guessCount < guessLimit) {
            printf("Enter a number: ");
            scanf("%d", &guess);
            guessCount++;
        } else {
            outOfGuesses = 1;
        }
    } /* A SECRET NUMBER VARIABLE IS SET. A GUESS VARIABLE IS CREATED, BUT NOT SET. MULTIPLE OTHER VARIABLES ARE SET. OUR WHILE LOOP HAS THE CONDITION OF WHILE 'guess' IS NOT EQUAL TO 'secretNumber' AND 'outOfGuesses' EQUALS ZERO. IT WILL GIVE THE USER THREE CHANCES TO GUESS CORRECTLY. AFTER THEY GUESS CORRECTLY OR USE UP THEIR THREE CHANCES, THE MESSAGE BELOW PRINTS OUT. */
    if(outOfGuesses == 1) {
        printf("Sorry! You Lose.\n");
    } else {
        printf("You Win!\n");
    }
    
    /********** FOR LOOPS **********/
    
    int i;

    for(i = 1; i <= 5; i++) {
        printf("%d\n", i);
    } /* THIS IS VIRTUALLY THE SAME CODE AS SEEN IN THE WHILE LOOP SECTION. */

    for(int j = 0; j < 6; j++) {
        printf("%d\n", luckyNumbers[j]);
    } /* THIS WILL PRINT OUT THE NUMBERS INSIDE THE 'luckyNumbers' ARRAY IN THE ARRAYS SECTION. */
    
    /********** 2D ARRAYS & NESTED LOOPS **********/
    
    int nums[3][2] = {
                    {1, 2},
                    {3, 4},
                    {5, 6}
                }; /* REMEMBER, FOR 2D ARRAYS, THE BRACKETED NUMBERS NEXT TO THE VARIABLE (WHEN INITIALIZING) ARE HOW MANY ITEMS ARE IN THE ARRAY, NOT THEIR INDEX NUMBER. */
    
    printf("%d\n", nums[0][1]); /* PRINTS OUT 2 BECAUSE 2 IS LOCATED AT THE 0 INDEXED ARRAY AND AT THE 1 INDEXED INSIDE THAT ARRAY. */

    int k, l;

    for(k = 0; k < 3; k++) {
        for(l = 0; l < 2; l++) {
            printf("%d, ", nums[k][l]);
        }
        printf("\n");
    } /* VERY IMPORTANT: THE 1ST FOR LOOP WILL HAPPEN ONCE, THEN THE FOR LOOP INSIDE OF IT WILL LOOP THROUGH IN ITS ENTIRETY (IN THIS CASE, TWICE) BEFORE THE 1ST LOOP WILL GO THROUGH ITS 2ND LOOP. */

    /********** MEMORY ADDRESSES **********/
    
    int ega = 30;
    double apg = 3.4;
    char edarg = 'A';

    printf("ega: %p\napg: %p\nedarg: %p\n", &ega, &apg, &edarg); /* '%p' ALLOWS YOU TO ACCESS THE MEMORY ADDRESS OF WHICHEVER VARIABLE YOU PLACE AFTER IT. REMEMBER TO PUT AN '&' BEFORE THE VARIABLE. */
    
    /********** POINTERS **********/

    /* A POINTER IS A TYPE OF DATA THAT IS A MEMORY ADDRESS. */
    
    int * pEga = &ega; /* HOW YOU STORE POINTERS; [data type] * p[variable name] = &[variable name] */
    double * pApg = &apg;
    char * pEdarg = &edarg;
    
    /********** DEREFERENCING POINTERS **********/
    
    /* DEREFERENCING BASICALLY MEANS USING A POINTER TO GRAB THE VALUE THE MEMORY ADDRESS IS HOUSING. */

    printf("%d\n", *pEga); /* DEREFERENCING THE 'pEga' POINTER. THIS SHOULD PRINT OUT 30. DON'T FORGET THE *. */
    
    /********** WRITING FILES **********/

    /* YOU CAN USE THIS TO CREATE/WRITE DIFFERENT FILE TYPES (HTML, CSS, JAVASCRIPT, ETC.) IF YOU WANT TO. */
    
    FILE * fpointer = fopen("employees.txt", "r"); /* TO READ FILE YOU WOULD REPLACE "w" WITH "r" AND TO APPEND THEM YOU WOULD REPLACE IT WITH "a". */

    fprintf(fpointer, "\nKelly, Customer Service\nToby, Human Resources");

    fclose(fpointer);
    
    /********** READING FILES **********/



    return 0;
}