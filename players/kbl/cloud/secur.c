inherit "/players/kbl/objs/thing";

#include "/players/kbl/cloud/cloud.h"
#include "/players/kbl/cloud/gen.h"

int ty;
string code;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    name = "cell monitor";
    short_desc = "Cell monitor";
    long_desc = "A hovering translusant ball with manysharp spines.\n";
    read_message = "Made by Cloud Developers... this part has been\n"+
                   "wiped away and another message says: @@code@@.\n";
    value = 100000;
    weight = 20;
    alt_name = "monitor";
    alias_name = "ball";
    ty = 1;
    code = "lightning";
  }
}

init()
{
  ::init();
  add_action("trap","say");
  add_action("trap","tell");
  add_action("trap","chat");
  add_action("trap","shout");
  add_action("trap","'",1);
}

trap(str)
{
  switch(query_verb())
  {
    case "say":
    case "tell":
    case "chat":
    case "shout":
    default:
        tell_room(TO,"A energy surge starts to build in this cloud cell!\n");
        gen_vib();
  }
}

gen_vib()
{
  int res1,res2,var1,var2;

  var1 = random(100);
  var2 = random(100);
  res1 = var1 - var2;
  res2 = var2 - var1;
  if(res1 > res2 && res2 > 0)
  {
    tell_object(TP,"A small dark blue ball zeros in on you!\n");
    say(CTPRN+" recieves a lightning strike from a small cloud cell!\n",TP);
    tell_object(TP,"The blue ball strikes you with powerful lightning!\n");
    if(present("cloud_control",TP)->query_type() < TO->query_type())
    {
      tell_object(TP,"You get slamed right out of this cell!!\n");
      say(CTPRN+" gets belted out of this cell completely!\n",TP);
      res1 = 1;
      while(res1)
      {
        var1 = random(sizeof(CCMAP->QIMM));
        res1 = CCMAPM(var1);
      }
      CCMAP->setup_cell(var1,"cha",9);
      MO(TP,CXMAP->QCT[var1]);
      command("l",TP);
    }
    say(CTPRN+"'s wand repels the dark blue balls' lightning!\n");   
    tell_object(TP,"Your cloud control wand repels the lightning!\n");
  }
}

query_type()
{
  return ty;
}

set_type(n)
{
  ty = n;
}

set_code(str)
{
  code = str;
}

code()
{
  return code;
}
