init() { add_action("xg","xg"); }
xg() {
int a;

  a=allocate(1);
  a[0]=a;
  printf("%O",a);
return 1;
}
