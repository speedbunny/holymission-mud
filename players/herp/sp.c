id(str) { return str=="sp"; }
init() { add_action("sp","sp"); }
sp() {
object ob;
string *s;

  /* s=get_dir("doc/examples/*"); */
  /* s=implode(get_dir("doc/examples/*"),"\n"); */
/* write("sizeof(s) "+sizeof(s)+"\n"); */
  s=({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
       21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44 });
  printf("%@10i\n",s);
  return 1;
}
