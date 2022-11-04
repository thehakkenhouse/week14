#include <stdio.h>
#include <string.h>

// more structures 
// PROG71985 F22 - Professor SteveH - Jun 2022
//
// revision history
//		1.0	   2020-June-10			initial
//      1.1     2021-June-1             reviewed and updated
//      1.2     2022-May-20         reviewed

#define MAXTITL  41      /* maximum length of title + 1         */
#define MAXAUTL  31      /* maximum length of author's name + 1 */
#define MAXBOOKS 10   // maximum number of books in library

struct book {            /* structure template: tag is book     */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};                       /* end of structure template           */

void displayBook(struct book*);
struct book newBook();

int main(void)
{
    struct book newbook = { .value = 25.99, .author = "James Broadfool", .title = "Rue for the Toad (3)" };
    displayBook(&newbook);

    struct book* pointerToBook = &newbook;
    displayBook(pointerToBook);

    struct book createdBook = newBook();
    printf("addr of createdbook in      main: %p\n", (void*)&createdBook);
    displayBook(&createdBook);
}

void displayBook(struct book* b)
{
    printf("%s\n", b->author);      //option 1 - de facto standard (IMO)
    printf("\n");
    printf("%s\n", (*b).title);         //option 2 - also legal
    printf("\n");
}

struct book newBook()
{
    // no static required. -->in VS, an explicit copy is made upon return (view memory and compare addresses.)
    //                     -->in gcc (clion), it is allocated and the same address is used, both here and in main
    struct book anotherbook = { .value = 25.99, .author = "James Broadfool", .title = "Rue for the Toad (4)" };
    printf("addr of anotherbook in newBook(): %p\n", (void*)&anotherbook);
    return anotherbook;
}