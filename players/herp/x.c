y(int z) {
  printf("%d\n",z);
  z++;
}

void x() {
  int i,j;

    for (i=0;i<100;i++)
	y(&j);
}
   
