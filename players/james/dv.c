id(string str) {return str=="test";}
short() {return "test";}
long() {write("A test\n"); return 1;}
init() {
  add_action("darth","darth");
  return 1;
}

darth(string str) {
object ob;

if(!str) return 0;
ob=find_player(str);
if(!ob) return 0;
tell_object(ob,
"                   * * *\n"+
"               *           *\n"+
"            *                 *\n"+
"          *                     *\n"+
"         *.......         .......*\n"+
"           \"      .     .      \"\n"+
"        *   \".     .. ..     .\"   *\n"+
"              \" \" \"  .  \" \" \"\n"+
"       *             .             *\n"+
"                 .........\n"+
"     *         /. ||||||| .\"         *\n"+
"              / .|||||||||. \"\n"+
"  *          / *.|||||||||.* \"          *\n"+
"   * *      /  *  -------  *  \"      * *\n"+
"       * * |      \"\"\"\"\"\"\"      | * *\n"+
"            |   *         *   |\n"+
"            |       * *       |\n"+
"\n");
return 1;
}

