init() {
    add_action("xx","xx");
}

xx() {
int i;

  i=3;
  printf("i = %d\n",i);
  yy(&i);
  printf("i = %d\n",i);
  return 1;
}

yy(int i) { i++; }

