inherit "room/room";
#include <lw.h>
#define TP this_player()
#define QRN query_real_name()
#define TPRN this_player()->query_real_name()
#define C capitalize
#define CTPN capitalize(this_player()->query_name())
#define CTPRN capitalize(TPRN)
int shield, athame, sword, cs;
mixed allowed, circle, dir;


string s_stat()
  {if (shield)
    {return "on";}
  return "off";}

void init_allow()
  {allowed=({"kawai","nobody","nobody","nobody",
  "nobody","nobody","nobody"});}

void init_circle()
  {circle=({0,0,0,0,0,0,0});}

void reset(int arg)
  {athame=1;
  sword=1;
  if(!arg)
    {cs=0;
    init_circle();
    init_allow();
    set_light(1);
    shield=0;
    short_desc="The wonderfully mystical workroom of Kawai!";
    no_castle_flag = 0;
    long_desc = 
    "Welcome to Kawai's Workroom!\n"+
    "You've entered Kawai's sacred chambers.  All around the room are various "+
    "lit candles and ornaments.  On the floor, a large circle is drawn, and an altar "+
    "stands in the center.\n"+
    "A sign is on the wall.\n";
    items = ({
    "circle","A magick circle used in ceremony",
    "candles","Various colored and scented candles",
    "candle","The room is adorned with various colored and scented candles",
    "rune","Though not understanding them, you sense their power",
    "runes","Though not understanding them, you sense their power",
    "ornament","Various magickal symbols",
    "sign","Try reading it",
    "ornaments","Various magickal symbols"});
    dest_dir = ({
    "/room/church", "church",
    "/room/post", "post",
"/players/matt/newworld/rooms/votebooth","vote",
    "/players/kawai/castle/entrance","castle",
    "/players/moonchild/misc/hut","hut",
    "/players/kawai/areas/passage1.c","area"});}
  ::reset(arg);}

string swords()
  {if(athame&&sword)
    {return "A small, white handled knife and a beautiful, cermonial sword lie on the altar";}
  else if(athame) 
    {return "A small, white handled knife is on the altar";}
  else if(sword) 
    {return "A beautiful, ceremonial sword is on the altar";}
  else
    {return "There is nothing on it";}}

void init()
  {::init();
  add_action("set_shield", "shield");
  add_action("set_who","allow");
  add_action("read_it","read");
  add_action("kick_em","boot");
  add_action("ec","enter");
  add_action("gc","get");
  add_action("gc","take");
  add_action("lc","leave");
  add_action("hs","pray");
  add_action("lat","look");}

status lat(string str)
  {if(!str) 
    {return 0;}
  if(str=="at altar")
    {writelw("The altar stands in the center of the circle, and is covered "+
    "with a red cloth.  Various runes are embroidered on to it.  "+
    swords()+".\n");
    return 1;}
  if(str=="at athame"||str=="at knife")
    {if(!athame)
      {return 0;}
    writelw("The small knife, bearing a series of runes inscribed on its white handle, is "+
    "the usual tool during the rituals performed in the circle.  The athame "+
    "eminates a strong magickal aura.\n");
    return 1;}
  if(str=="at sword")
    {if(!sword)
      {return 0;}
    writelw("The sword is perhaps one of the most beautifully crafted weapons you've "+
    "ever seen.  Inscribed on the blade is a series of runes, although you don't "+
    "quite understand them.  The blade is an unfamiliar alloy, and seems unusually "+
    "sharp and strong.\n");
    return 1;}
  return 0;}

int query_circle()
  {int i, ret;
  ret=0;
  for(i=0;i<=6;i++)
    {if(TPRN==allowed[i])
      {ret=circle[i];}}
  return ret;}

void set_circle(int arg)
  {int i;
  for(i=0;i<=6;i++)
    {if(TPRN==allowed[i])
      {circle[i]=arg;}}}

int query_allow()
  {int i, ret;
  ret=0;
  for(i=0;i<=6;i++)
    {if(TPRN==allowed[i])
      {ret=1;}}
  return ret;}

status ec(string str)
  {if(!str)
    {notify_fail("Enter what?\n");
    return 0;}
  if(str=="circle")
    {if(!query_allow()) 
      {write("A magickal force prevents you from entering.\n");
      say(CTPRN+" tries to enter the circle.\n");
      return 1;}
    if(query_circle())
      {write("You're already in the circle!\n");
      say(CTPRN+" looks confused...\n");
      return 1;}
    write("You feel warm inside as you enter the circle.\n");
    set_circle(1);
    say(CTPRN+" enters the circle.\n");
    return 1;}
  return 0;}

status gc(string str)
  {object ob, kn, at;
  if(!str)
    {notify_fail(capitalize(query_verb())+" what?\n");
    return 0;}
  if(str=="knife"||str=="athame"||str=="sword")
    {if(present(str))
      {return 0;}
    if(!query_circle())
      {write("You can't reach them from outside the circle.\n");
      say(CTPRN+" tries to take the sacred tools, but can't reach.\n");
      return 1;}
    if((str=="knife"||str=="athame")&&athame)
      {if(transfer(at=clone_object("/players/kawai/obj/athame"),TP))
        {write("You can't take it...\n");
        say(CTPRN+" tries to take the athame.\n");
        destruct(at);
        return 1;}
      write("You take the athame.\n");
      say(CTPRN+" takes the athame!\n");
      athame=0;
      return 1;}   
    else if(str=="sword"&&sword)
      {if(transfer(at=clone_object("/players/kawai/obj/sword"),TP))
        {write("You can't take it...\n");
        say(CTPRN+" tries to take the sword!\n");
        destruct(at);
        return 1;}
        write("You take the sword.\n");
      say(CTPRN+" takes the sword!\n");
      sword=0;
      return 1;}
    else
      {write("Its not here...\n");
      return 1;}
    return 1;}
  return 0;}

status lc(string str)
  {if(!str)
    {notify_fail("Leave what?\n");
    return 0;}
  if(str=="circle")
    {if(!query_circle())
       {write("You're not in the circle.\n");
       say(CTPRN+" looks confused.\n");
       return 1;}
    write("You leave the circle.\n");
    set_circle(0);
    say(CTPRN+" leaves the circle.\n");
    return 1;}
  return 0;}

status hs()
  {if(!query_circle())
    {return 0;}
  this_player()->heal_self(2000);
  write("You sit down and meditate.\n"+
  "When you are finished, you feel rejuvinated.\n");
  say(CTPRN+" mediates in the circle.\n");
  return 1;}

status block(string str)
  {if(query_circle())
    {write("You must leave the circle first!\n");
    say(CTPRN+" tries to leave, but can't!\n");
    return 1;}
  else
    {return 0;}}

status read_it(string str)
  {if(!str)
    {notify_fail("Read what?\n");
    return 0;}
  if(str=="sign")
    {write("Workroom Security v3.2 by Kawai\n"+
    "=================================================================\n"+
    "allow <name> as guest <pos>    changes the name of\n"+
    "                               the allowed guest position (1-6).\n"+
    "boot <name>                    kick a guest from the room.\n"+
    "boot <name> to <loc>           boot to church, hell, void, or nowhere\n"+
    "shield on/off                  turns the shield on or off\n"+
    "                               or check status.\n"+
    "\n");
    return 1;}
  return 0;}


status kick_em(string str)
  {string who, where;
  object ob;
  if(!str)
    {say(CTPRN+" looks confused...\n");
    return 1;}  
  if(!query_allow())
    {say(CTPN+" thinks of kicking someone, but has no authority.\n");
    write("You have no authority here!\n");
    return 1;}
  if(sscanf(str,"%s to %s",who,where)==2)
    {if(!(ob=present(who))) {write(C(str)+" isn't here!\n");
    say(CTPRN+" thinks of kicking someone...\n");
    return 1;}
    if(who=="kawai") 
      {write("You can't kick him!\n");
      say(CTPRN+" tried to kick kawai!\n");
      tell_object(ob,"You are kicked from Kawai's workroom!\n");
      move_object(ob,"players/kawai/hell");
      tell_room(ob,C(ob->QRN)+" lands with a thud!\n");
      command("look",ob);
      tell_room("/players/kawai/workroom",C(ob->QRN)+" was sent to hell!\n"); 
      return 1;}                     
    if(where=="hell")
      {tell_object(ob,"You are kicked from Kawai's workroom!\n");
      move_object(ob,"players/kawai/hell");
      tell_room(ob,C(ob->QRN)+" lands with a thud!\n");
      command("look",ob);
      tell_room("/players/kawai/workroom",C(ob->QRN)+" was sent to hell!\n"); 
      return 1;}
    if(where=="nowhere")
      {if(CTPRN!="Kawai")
        {write("You can't!\n");
        say(CTPRN+" tries to destruct someone!\n");
        return 1;}
      tell_object(ob,"You are obliterated!!\n");
      tell_room("/players/kawai/workroom",C(ob->QRN)+" was destructed!\n");
      destruct(ob);
      return 1;}
    if(where=="church")
      {tell_object(ob,"You are kicked from Kawai's workroom!\n");
      move_object(ob,"room/church");
      tell_room(ob,C(ob->QRN)+" lands with a thud!\n");
      command("look",ob);
      tell_room("/players/kawai/workroom",C(ob->QRN)+" was sent to the church!"); 
      return 1;}
    if(where=="void")
      {tell_object(ob,"You are kicked from Kawai's workroom!\n");
      move_object(ob,"room/void");
      tell_room(ob,C(ob->QRN)+" lands with a thud!\n");
      command("look",ob);
      tell_room("/players/kawai/workroom",C(ob->QRN)+" was sent to the void!"); 
      return 1;}
    else
      {write("Possible locations: hell, church, void\n");
      return 1;}}
  if(sscanf(str,"%s to",who)==1) 
    {write("Possible locations: hell, church, void\n");
    return 1;}
  if(sscanf(str,"%s",who)==1)
    {if(!(ob=present(who))) 
      {write(C(str)+" isn't here!\n");
      say(CTPRN+" thinks of kicking someone...\n");
      return 1;}
      tell_object(ob,"You are kicked from Kawai's workroom!\n");
      move_object(ob,"players/kawai/hell");
      tell_room(ob,C(ob->QRN)+" lands with a thud!\n");
      command("look",ob);
      tell_room("/players/kawai/workroom",C(ob->QRN)+" was sent to hell!\n");
      return 1;}
  return 0;}


status set_who(string str)
  {string name;
  int pos,i;
  if(!str)
    {write("List of Guests\n"+
    "==================\n");
    for(i=0;i<=6;i++)
      {write(i+") "+allowed[i]+"\n");}
      say(CTPRN+" reads the guest list.\n");
      return 1;}
  if(!query_allow())
    {say(CTPN+" inquires about the guest list, but has no authority.\n");
    write("You have no authority here!\n");
    return 1;}   
  else if(sscanf(str,"%s as guest %d",name,pos)==2)
    {if(pos>=1 && pos<=6)
      {write(capitalize(name)+" is now allowed as guest "+pos+".\n");
      say(CTPRN+" changes guest position "+pos+" to "+C(name)+".\n");
      allowed[pos]=name;
      return 1;}
    write("Valid guest positions are 1 through 6.\n");
    say(CTPRN+" inquires about the guest list.\n");
    return 1;}
  else if(sscanf(str,"%s as guest",name)==1)
    {write("Valid guest positions are 1 through 6.\n");
     say(CTPRN+" inquires about the guest list.\n");
     return 1;}
  write("Must specify a guest position.\n");
  say(CTPRN+" inquires about the guest list.\n");
  return 1;}

status set_shield(string str)
  {if(!str)
    {write("Shield is "+s_stat()+".\n");
    return 1;}
  if(!query_allow())
    {say(CTPN+" inquires about the shield, but has no authority.\n");
    write("You have no authority here!\n");
    return 1;}   
  if(str == "on")
    {if(shield)
      {write("It is already on!\n");
      return 1;}
    write("You set the shield on.\n");
    say("You feel a warm feeling surround the room, as "+CTPRN+" turns the shield on.\n"); 
    shield = 1;
    return 1;}
  if(str == "off")
    {if(!shield)
      {write("It is already off!\n");
      return 1;}
    write("You snap your fingers and the shield shut off.\n");
    say("The bright globe surrounding the room disappears as "
    +CTPRN+" turns the shield off\n");
    shield = 0;
    return 1;}
  write("Set shield to what?\n");
  say(CTPN+" inquires about the shield.\n");
  return 1;}



