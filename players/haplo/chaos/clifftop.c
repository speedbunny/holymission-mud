/* Top of High Cliff */
// whisky 02.03.95 bug in the give fun

#include "/players/haplo/chaos/T.h"
int mess;
object ole;

reset(arg)
{
  if(arg)
   return;
  if(!ole || !living(ole))
  {
  ole = clone_object("/players/haplo/chaos/monsters/ole_man");
    transfer(ole,this_object());
  }
}

short()
{
  return "Ancient climb down spot";
}

long()
{
int val;
  write(short()+".\n");
  write("The view from here is tremendous! The valley west of you stretchs\n");
  write("to a distance sea. Approximately 300km/180miles distant. The soft\n");
  write("blue sea of trees in the foreground accent the blueish white\n");
  write("cliffs you now stand top of. To the north you see the giant pines\n");
  write("brushing against the cliffs. To the south stands a mountain\n");
  write("range, rugged and forbidding. Eastward lies a tall thin pyramid\n");
  write("type structure, poking up on this long plane stretching east.\n");
  write("Obvious exit is down\n");
  if(ole)
  {
   write("A basket.\n");
   val = random(6);
   if(val == 2)
   write("Ole man looks up at you and smiles.\n");
   if(val == 4)
    write("Ole man mumbles something in a ancient tongue.\n");
   if(val == 0)
    write("Ole man stretchs his old bones then sits in lotus position.\n");
  }
}

init()
{
   set_light(1);
  add_action("ask","ask");
  add_action("think","think");
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("look_it","exa");
  add_action("look_it","l");
  add_action("look_it","examine");
  add_action("down","down");
  add_action("give","give");
  add_action("get","get");
}

down()
{
  int val;

  val = this_player()->query_dex()-this_player()->query_intoxination()/2;
  if(val < 20)
  {
    write("You do NOT feel like going down that cliff!\n");
    return 1;
  }
  write("You climb down to...\n");
  this_player()->move_player("climbing down#players/kbl/cliff3");
  return 1;
}

east()
{
  write("You head east across plane to...\n");
  this_player()->move_player("east#players/kbl/plane1");
  return 1;
}

north()
{
  write("You move northward towards the giant pines and...\n");
  this_player()->move_player("north along cliff#players/kbl/northcliff1");
  return 1;
}

south()
{
  write("You head towards the mountains.\n");
  this_player()->move_player("south#players/kbl/southcliff1");
  return 1;
}

look_it(str)
{
  int val;

  if(!str)
   return;
  if(str == "at valley" || str == "valley")
  {
    write("You scan out over the cliff to see the lust blue forest\n");
    write("stretching out towards the horizon west. The giant pines\n");
    write("catch your eye, their crimson needles just visible over the\n");
    write("cliff. The air is so fresh that flows up from the valley\n");
    write("that your mind floats as if on a cushion of air. You think\n");
    write("'Ahhhhhhhhh....'\n");
    return 1;
  }
  if(str == "at mountains" || str == "mountains")
  {
    write("The distant mountains seem familiar in some way. But you see\n");
    write("the slopes of these mountains are very steep and jagged. The\n");
    write("path leading north takes you to the base of the mountains.\n");
    return 1;
  }
  if(str == "at pyramid" || str == "pyramid")
  {
    write("You see the pyramid is a black spire coming out of\n");
    write("the ground plane. Its quite some distance away, so your\n");
    write("not sure of its absolute size.\n");
    return 1;
  }
  if(str == "at giant pines" || str == "giant pines")
  {
    val = random(5);
    mess = val;
    if(val == 4)
     write("You see a large bird flying high overhead.\n");
    if(val == 1)
     write("The pines seem to shimmer in the light and move to unfelt wind.\n");
    write("These giant pines are barely visible from here. You don't see\n");
    write("any real detail.\n");
    return 1;
  }
  if(str == "at cliff" || str == "cliff")
  {
    write("The quartz crystal here is flaking off and blowing around in\n");
    write("the wind. The quartz powder blows south towards the mountains.\n");
    val = random(5);
    mess = val;
    if(val == 1)
     write("You see a fly land near you on the ground.\n");
    if(val == 3)
     write("A gust of wind blows the powder in you face. It decays fast!\n");
    if(val == 0)
     write("A large bird flies overhead towards the giant pines.\n");
    return 1;
  }
  if(ole)
  {
    if(str == "at basket" || str == "basket")
    {
      write("This basket is woven from a straw like metal. The basket\n");
      write("glows a soft blue and has the letters Kbl inscribed on it.\n");
      return 1;
    }
  }
  if((str == "at bird" || str == "bird") && mess == 4)
  {
    write("Its so high up that you can't make out any detail. It leaves\n");
    write("flying northward.\n");
    mess = 0;
    return 1;
  }
  if((str == "at fly" || str == "fly") && mess == 1)
  {
   write("golden eyes. It flies off as you look at it.\n");
    mess = 0;
    return 1;
  }
}

think(str)
{
  if(!str)
   return;
  if(ole)
  {
    if(str == "about ole man")
    {
      if(this_player()->query_int() > 20)
      {
        write("Ole man thinks to you: You think about me? Think about others.\n");
        return 1;
      }
      if(this_player()->query_int() > 10)
      {
        write("Ole man thinks to you: Gain some intelligence, please!\n");
        return 1;
      }
      write("You can't seem to concentrate long enough.\n");
      return 1;
    }
    if(str == "about pyramid")
    {
      if(this_player()->query_int() > 15)
      {
         write("Ole man thinks to you: Only easy entrance to pyramid is\n");
         write("by letting go.\n");
         return 1;
      }
      write("You can't seen to think about the pyramid.\n");
      return 1;
    }
    if(str == "about giant pines")
     {
       if(this_player()->query_int() > 20)
       {
         write("Ole man thinks to you: The giant pines hold a part you need.\n");
         return 1;
       }
       write("You seem to be lost in a ocean of thoughts!\n");
       return 1;
     }
     if(str == "about cliff")
     {
       if(this_player()->query_int() > 15)
       {
         write("Ole man thinks to you: Let go, the cliffs are the place.\n");
         return 1;
       }
       write("You need more intelligence!\n");
       return 1;
     }
     if(str == "about mountains")
     {
       if(this_player()->query_int() > 20)
       {
         write("Ole man thinks to you: The MASTER lives there!\n");
         return 1;
       }
       write("You think that the mountains are mountains.\n");
       return 1;
     }
  }
}

ask(str)
{
  if(!str)
   return;
   if(ole && living(ole))
   {
  if(str == "about pyramid")
  {
    write("Ole man tells you: Pyramid is Kbls Library. Many evil\n");
    write("creatures have taken over the area surrounding it. For\n");
    write("some reason tho these evil creatures have not been able\n");
    write("to gain access into the library. They do not possess the\n");
    write("Library Key.\n");
    return 1;
  }
  if(str == "about cliff")
  {
    write("Ole man tells you: Many secrets the cliff hides. You must\n");
    write("test the inner limits of mortality. The way is not really\n");
    write("clear.\n");
    return 1;
  }
  if(str == "about giant pines")
  {
    write("Ole man tells you: I've only been there in my youth when the\n");
    write("were not so big and the cliff was farther west it was.\n");
    command("sigh",ole);
    write("Even back then the dark elfs use to torment adventurers, like\n");
   write("yourselves. Bring the Black Heart Jem to me, I will give you\n");
   write("the knowledge to help you with some secrets of Kbl's library.\n");
   command("smile "+this_player()->query_real_name(),ole);
    return 1;
  }
  }
}

fix_up(mon)
{
  mon->set_name("Ole man");
  mon->set_alias("man");
  mon->set_alt_name("elf king");
  mon->set_race("elf");
  mon->set_level(80);
  mon->set_hp(7000);
  mon->set_sp(7000);
  mon->set_al(7000);
  mon->set_aggressive(0);
  mon->set_gender(1);
  mon->set_guild(7);
  mon->set_str(50);
  mon->set_dex(50);
  mon->set_int(80);
  mon->set_wis(80);
  mon->set_con(55);
  mon->set_chr(55);
  mon->set_ac(5);
  mon->set_wc(10);
  mon->set_short("A Ole man");
  mon->set_long("He is very old, but extremely powerful. The blue power\n"+
                "in his elvin eyes, shines like a star at night. Wearing\n"+
                "white robes of silk that flows with every wind movement.\n"+
                "Two Ion stones orbit his head. One is Blue the other is\n"+
                "Red.\n");
  mon->set_chance(10);
  mon->set_spell_mess1("Ole man shocks you!\n");
  mon->set_spell_mess2("Ole man casts a huge fireball at you!\n");
  mon->set_spell_dam(100);
}

get(str)
{
  if(!str)
   return;
  if(ole)
  {
    if(str == "basket")
    {
      write(ole->query_name()+" stops you from getting basket.\n");
      return 1;
    }
  }
}

give(str)
{
  object note;
  if(!str)
   return 0;
  str = lower_case(str);
  if(str == "blackheart to man" || str == "black heart to man" ||
     str == "blackheart to ole man" || str == "black heart to ole man" ||
     str == "black heart to ole man" || str == "black heart to man")
  {
    if (present("black heart",this_player()))
    {
      write(ole->query_name()+" exclaims: You are wise!\n");
      write("Ole man pulls something out of his basket.\n");
     note = clone_object("players/kbl/objs/kblnote");
      transfer(note,this_player());
      write("Ole man thinks to you: The note has things on it that will\n");
      write("guide you in the workings of a few things. Read it carefully.\n");
      write("Ole man smiles at you knowningly.\n");
      write("Ole man says to you: Elvin Cooshee dogs give Star Leafs to Elfs.\n");
      write("Ole man pulls a book from the basket and hands it to you.\n");
      transfer(clone_object("players/kbl/objs/chaos"),this_player());
      return 1;
    }
    return 1;
  }
}

jem()
{
  int no_obj;
  object ob,gobj;

  no_obj = 0;
  ob = first_inventory(this_player());
  gobj = clone_object("players/kbl/objs/blackheart");
  if(ob && gobj)
  {
    while(ob)
    {
      if(ob->query_name() == gobj->query_name())
      {
        write("Ole man takes Black Heart crystal from you.\n");
        write("Ole man puts jem in basket.\n");
        destruct(ob);
        destruct(gobj);
        return 1;
      }
      else
        ob = next_inventory(ob);
    }
  }
  else
  {
    write("You do not have any inventory!\n");
    destruct(gobj);
    return 0;
  }
  if(no_obj == 0)
  {
    destruct(gobj);
    return 0;
  }
}
