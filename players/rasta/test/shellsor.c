//     Shell Sort
//      Roland Hartich 10. Oktober 1992
//
char a[20][30];
char *f[] = {"Roland" , "Hartich" , "8955053", "Anna" , "Josefine",
	     "Julie" , "Algorithmen", "Datenstrukturen", "Nikolaus Wirth",
	     "Genius Mouse driver", "Nonsense" , "Post it", "Wintersemester",
	     "Sommersemester", "Schweindi" , "Postscript" , "Jamaica" ,
	     "Regenschirm" , "Motherboard" , "Rucksack" } ;

void shellsort(int N)
{
    int j,i,h=1,ok;
    char v[30];

//  Inkrement berechnen

  while (h<=N) h=3*h +1;  // Folge ..,1093,354,121,40,13,4,1


  while(h>=1)
  {


    // h-sortierte Folge herstellen

    for(i=h+1;i<=N;i++)
    {
       j = i;
       strcpy(v,a[i-1]);             //  v  = a[i-1];
       ok = 1;

       while (strcmp(a[j-h-1],v)>0 && ok)
       {
	 strcpy(a[j-1],a[j-h-1]);    //  a[j-1]=a[j-h-1];
	 j=j-h;
	 ok = (j> h);
       }
       strcpy(a[j-1],v);             //     a[j-1] = v;
     }
     h/=3;

 }
}

void main()
{
 int i;

 for(i=0;i<20;i++) strcpy(a[i],f[i]);

 puts("Unsortiert:");
 for(i=0;i<20;i++) {printf("%s ",a[i]);  printf("\n");}

 shellsort(20);

 puts("\nSortiert:");
 for(i=0;i<20;i++) {printf("%s ",a[i]);  printf("\n");}

 }
