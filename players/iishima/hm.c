/* Auto Strict Typing -- Gotta love it babe! HELL YEAH! */

void reset(int arg)
{
 string *files;
 string str;
 string *s;
 int x;

 str = "";
 x = sizeof(files = get_dir("/players/iishima/area/monsters/"));
 write("Converting from Archon To HM\n");
 while (x--)
 {
  write("Processing "+files[x]+" .... ");
  str = read_file("/players/iishima/area/monsters/"+files[x]);
  str = implode(explode(str, "reset(arg)"), "void reset(int arg)");
  str = implode(explode(str, "init(arg)"), "void init(int arg)");
  write_file("/players/iishima/area/mon/"+files[x], str);
  write("Done.\n");
 }
}
