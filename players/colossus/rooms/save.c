void save_func(string ld, string sd, string filename, string *exits,
               string *commands, int light, string name, string extra) {
string content;
string exitstring;
string cmdstring;
string new_extra;
int i;
  filename += ".c";
  new_extra = extra;
  new_extra = implode(explode(new_extra, "\n"), "\\\n");
  new_extra = implode(explode(extra, "\""), "\\\"");
  extra = implode(explode(extra, "\\n"), "\n");
  exitstring = "({";
  for (i=0;i<sizeof(dest_dir)-1;i++)
exitstring += "\"" + dest_dir[i] + "\",\n     ";
  if (sizeof(dest_dir))
exitstring += "\"" + dest_dir[sizeof(dest_dir)-1] + "\"}),\n    ";
  else
    exitstring = 0;
  cmdstring = "({";
  for (i=0;i<sizeof(commands)-1;i++)
    cmdstring += "\"" + commands[i] + "\","; 
if(sizeof(dest_dir))
    cmdstring += "\"" + commands[sizeof(commands)-1] +"\"})";
  else
    cmdstring = 0;
  content =
"inherit \"/room/room\";\n" +
    "inherit \"/w/colossus/house/hfunc/decorate\";\n" +
    "inherit \"/w/colossus/house/hfunc/build\";\n" +
    "inherit \"/w/colossus/house/hfunc/make\";\n" +
    "\n"+
    "string file;\n" +
    "object door;\n" +
    "\n"+
    "reset() {\n" +
    "\n" +
    "  if (door) return;\n" +
    "  ::reset();\n" + extra +
    "}\n" +
    "\n" +
    "create() {\n" +
    "  ::create();\n" +
    "  set_long(\"" + ld + "\");\n" + 
  "  set_short(\"" + sd + "\");\n" +
    "  set_exits(" + exitstring + cmdstring + ");\n" +
    "  set_light(" + light + ");\n" +
    "  reset();\n" +
    "}\n"+
    "\n" +
    "query_owner() { return \"" + name + "\"; }\n" +
    "\n" +
    "query_long_desc() {\n" +
    "  return \"" + ld + "\"; }\n" +
    "\n" +
    "query_extra() {\n" +
    "  return \"" + new_extra + "\"; }\n" +
    "\n" +
    "int redecorate() {\n" +
    "  file = file_name(this_object());\n" +
    "  decorate(this_object(),file);\n" +
    "  return 1;\n" +
    "}\n" +
    "\n" +
    "int rebuild(string direction) {\n" +
    "  file = file_name(this_object());\n" +          
    "  build_func(file, direction);\n" +
    "  return 1;\n" +
    "}\n" +
    "\n" +
    "int remake(string direction) {\n" +
    "  file = file_name(this_object());\n" +
    "  make_func(file, direction);\n" +
    "  return 1;\n" +
    "}\n" +
    "\n" +
    "init() {\n" +
    "  ::init();\n" +
    "  add_action(\"redecorate\",\"decorate\");\n" +
    "  add_action(\"rebuild\",\"build\");\n" +
    "  add_action(\"remake\",\"make\");\n" +
    "}\n";

  rm(filename);
  write_file(filename, content);
  return;
}      
