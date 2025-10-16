#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define MAX_BOOKS 500000 
#define TITLE_LEN 100 
#define AUTHOR_LEN 50 
typedef struct { 
int id; 
char title[TITLE_LEN]; 
char author[AUTHOR_LEN]; 
int available; 
} Book; 
Book books[MAX_BOOKS]; 
int bookCount = 0; 
const char *categories[] = { 
"Data Structures", "Algorithms", "C Programming", "Java Programming", 
"Operating Systems", "Computer Networks", "Database Systems", 
"Artificial Intelligence", "Machine Learning", "Cyber Security", 
"Discrete Mathematics", "Software Engineering", "Cloud Computing", 
"Blockchain", "Computer Graphics" 
}; 
const char *authors[] = { 
"Yashwant Kanetkar", "E. Balagurusamy", "Andrew Tanenbaum", 
"Silberschatz", "Herbert Schildt", "Donald Knuth", 
"Mark Zuckerberg", "Alan Turing", "Tim Berners-Lee", 
"Ada Lovelace", "Grace Hopper", "Linus Torvalds", 
"Bjarne Stroustrup", "James Gosling", "John McCarthy" 
}; 
void loadSampleBooks() { 
int catCount = sizeof(categories) / sizeof(categories[0]); 
int authCount = sizeof(authors) / sizeof(authors[0]); 
for (int i = 0; i < MAX_BOOKS; i++) { 
books[i].id = 1000 + i; 
sprintf(books[i].title, "%s - Volume %d", categories[i % catCount], (i / catCount) + 1); 
sprintf(books[i].author, "%s", authors[i % authCount]); 
books[i].available = (i % 3 != 0); 
} 
bookCount = MAX_BOOKS; 
printf("Library Loaded with %d Books \n", bookCount); 
} 
void printBook(Book b) { 
printf("ID: %d | Title: %s | Author: %s | Available: %s\n", 
b.id, b.title, b.author, b.available ? "Yes" : "No"); 
} 
int binarySearchByID(int id) { 
int l = 0, r = bookCount - 1; 
while (l <= r) { 
int mid = (l + r) / 2; 
if (books[mid].id == id) return mid; 
else if (books[mid].id < id) l = mid + 1; 
else r = mid - 1; 
} 
return -1;
} 
void searchByTitleKeyword(char *keyword) { 
int found = 0, count = 0; 
char more; 
for (int i = 0; i < bookCount; i++) { 
if (strstr(books[i].title, keyword)) { 
printBook(books[i]); 
found = 1; 
count++; 
if (count % 10 == 0) { 
printf("\nShow more results? (y/n): "); 
scanf(" %c", &more); 
if (more != 'y' && more != 'Y') break; 
} 
} 
} 
if (!found) 
printf("No matching titles found for keyword: %s\n", keyword); 
} 
int main() { 
int choice, id, idx; 
char keyword[50]; 
loadSampleBooks(); 
while (1) { 
printf("\n--- Library Book Search System ---\n"); 
printf("1. Search by ID (Binary)\n");
 printf("2. Search by Title Keyword (with pagination)\n"); 
        printf("3. Display First 20 Books\n"); 
        printf("0. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter Book ID: "); 
                scanf("%d", &id); 
                idx = binarySearchByID(id); 
                if (idx >= 0) printBook(books[idx]); 
                else printf("Book not found!\n"); 
                break; 
 
            case 2: 
                printf("Enter keyword in title: "); 
                scanf(" %[^\n]s", keyword); 
                searchByTitleKeyword(keyword); 
                break; 
 
            case 3: 
                for (int i = 0; i < 20 && i < bookCount; i++) 
                    printBook(books[i]); 
                break; 
 
            case 0: 
                printf("Exiting program.\n"); 
                exit(0); 
 
default: 
printf("Invalid choice!\n"); 
} 
} 
return 0; 
} 