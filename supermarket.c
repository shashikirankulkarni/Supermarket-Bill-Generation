/* Super Market Bill Generation */

#include<stdio.h>


struct superMarket {
  char name[30];
  int id, price;
};

struct bill {
  char itemname[25];
  int itemqty;
  int itemprice;
  int itemid;
}
b[50];

// adds items
void addrecord() {
  struct superMarket s;
  FILE * fp;
  char ch;
  fp = fopen("item_list.txt", "a+");
  printf("\nEnter Item id: ");
  scanf("%d", & s.id);

  printf("\nEnter Item name: ");
  scanf(" %s", s.name);

  printf("\nEnter Item price: ");
  scanf("%d", & s.price);

  fprintf(fp, "%d %s %d\n", s.id, s.name, s.price);
  fclose(fp);
  printf("\nItem added successfully!");
}

// searches item
void showrecord() {
  struct superMarket s;
  FILE * fp;
  int id, status = 0;
  fp = fopen("student_mark_list.txt", "a+");
  if (fp == NULL) {
    printf("\nItem does not exists!");
  } else {
    printf("\nEnter Item id: ");
    scanf("%d", & id);
    printf("\nid\tItem\t Price");
    while (fscanf(fp, "%d %s %d\n", & s.id, s.name, & s.price) != EOF) {
      if (id == s.id) {
        printf("\n%d\t%s\t%d", s.id, s.name, s.price);
        status = 1;
      }
    }
    fclose(fp);
  }
  if (status == 0) {
    printf("\nItems does not exists!");
  }
}

// deletes item
void deleterecord() {
  struct superMarket s;
  FILE * fp, * fp_temp;
  int id, status = 0;
  fp = fopen("item_list.txt", "r+");
  fp_temp = fopen("item_list_temp.txt", "a+");
  if (fp == NULL) {
    printf("\nItem does not exists!");
  } else {
    printf("\nEnter Item id: ");
    scanf("%d", & id);
    while (fscanf(fp, "%d %s %d\n", & s.id, s.name, & s.price) != EOF) {
      if (id != s.id) {
        fprintf(fp_temp, "%d %s %d\n", s.id, s.name, s.price);
      } else {
        status = 1;
      }
    }
    if (status == 1) {
      printf("\nItem deleted with id : %d", id);
    }
    fclose(fp);
    fclose(fp_temp);
    remove("item_list.txt");
    rename("item_list_temp.txt", "item_list.txt");
  }
}

// show all the items
void showall() {
  struct superMarket s;
  FILE * fp;
  fp = fopen("item_list.txt", "a+");
  if (fp == NULL) {
    printf("\nItem does not exists!");
  } else {
    printf("\nid\tItem\t\tPrice");
    while (fscanf(fp, "%d %s %d\n", & s.id, s.name, & s.price) != EOF) {
      printf("\n%d\t%s\t\tRs %d", s.id, s.name, s.price);
    }
    fclose(fp);
  }
}

void main() {
  struct superMarket s;
  int option, n, items, itemId, qty, ans, i, total = 0;
  int id, status = 0;
  printf("\nWelcome to Super Market\n-------------------------");

  printf("\n\nPlease Choose Mode\n1.Admin\n2.Customer");
  scanf("%d", & n);

  if (n == 1) {

    do {
      printf("\n\n\n1 -> add record\n2 -> delete record\n3 -> show record\n4 -> show all\n5 -> exit");
      printf("\nEnter option: ");
      scanf("%d", & option);
      switch (option) {
      case 1:
        addrecord();
        break;
      case 2:
        deleterecord();
        break;
      case 3:
        showrecord();
        break;
      case 4:
        showall();
        break;
      case 5:
        return;
      default:
        printf("\nInvalid option!");
      }
    } while (1);;
  }
  if (n == 2) {
    printf("\nEnter the number of items bought\n");
    scanf("%d", & items);

    for (i = 0; i < items; i++) {

      printf("\nEnter the ID of item");
      scanf("%d", & itemId);

      printf("\nEnter Quantity of Item");
      scanf("%d", & qty);

      struct superMarket s;
      FILE * fp;

      fp = fopen("item_list.txt", "a+");
      if (fp == NULL) {
        printf("\nItem does not exists!");
      } else {

        while (fscanf(fp, "%d %s %d\n", & s.id, s.name, & s.price) != EOF) {
          if (itemId == s.id) {

            b[i].itemid = s.id;
            strcpy(b[i].itemname, s.name);
            //b[i].itemname=s.name;
            b[i].itemprice = s.price;
            b[i].itemqty = qty;

            status = 1;
          }
        }
        fclose(fp);
      }
      if (status == 0) {
        printf("\nItems does not exists!");
      }

    }

    printf("\n\n\n\n\n");

    printf("\t\t   Item name   Quantity   Price\n");

    for (i = 0; i < items; i++) {
      ans = b[i].itemprice * b[i].itemqty;
      printf("\t\t\t%s\t%dx%d\t=Rs.%d\n", b[i].itemname, b[i].itemprice,
        b[i].itemqty, ans);
      total = total + ans;

    }

    printf("\t\t----------------------------------\n");
    printf("\n \t\tTotal price to be paid is Rs.%d\n", total);
    printf("\t\t----------------------------------\n");
    printf("\n\t\t\tThank you Visit again!!!");

  }
}
