string type;
string code;


short()
{
 return "A glowing crystal";
}

long()
{
 write("\nA long rod-like crystal.  It is rough, and has many facets which\n reflect the light which glows from within.\n");
}

id( strang)
{
 if ( ( strang == "crystal" )||( strang == "glowing crystal") )
   return 1;
 return 0;
}

get()
{
  return 1;
}

query_value()
{
 return 200;
}

query_type() { return type; }
query_code() { return code; }

set_type( str) { type = str; }
set_code( str) { code = str; }

init()
{
}

reset( arg)
{
 if(arg)
   return;
 type = 0;
 code = 0;
 set_light(100);
}

