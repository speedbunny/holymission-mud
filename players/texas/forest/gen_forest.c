/* Tex's Generic forest file
*  Created 25 March 1998
*
*  The clone_list() function below simply creates a different monster
*  or no monster at all depending on the value of a random number
*  and then sets the various variables required by /obj/monster.
*  This simply reduces the number of files for simple monsters.
*
*  In case you are confused the syntax used below equates to this:
*
*  (arg) ? return x : return y
*
*
*
*  if (arg)
*  {
*   return x;
*  }
*  else
*  {
*  return y;
*  }
*
*
* it makes no difference which you use. I just prefer the first method.
*
*/
inherit "/room/room";

string query_forest_desc();
string DESC;
int t;

void reset(int flag)
{
if(!flag) {
t = random(100);

    clone_list = ({

     (t<50)?0:1,(t<50)?0:(t>95)?1:random(8)+1,
     (t>95)?"treant":(t>80 && t<96)?"bat":(t>50 && t<81)?"snake":0,
     "obj/monster",
     ({
     "set_name",(t>95)?"treant":(t>80 && t<96)?"bat":(t>50 && t<81)?"snake":0,
     "set_level",(t>95)?15:(t>80 && t<96)?5:8,
     "set_short",
     (t>95)?"A large living tree":
     (t>80 && t<96)?"A small bat":
     "A hissing snake",
     "set_long",
     (t>95)?"A large Evil looking tree with long slender limbs":
     (t>80 && t<96)?"A small pathetic bat which flaps about harmlessly":
     (t>50 && t<81)?"A writhing snake with venomous fangs\n":0
        })
     });



DESC = "/players/texas/forest/descriptions_file"->query_forest_desc();

set_light(100);
short_desc = "Somewhere in the Old Wood";
long_desc = DESC;

items = ({

	"wood","The Infamous Old Forest",
	"woods","The Infamous Old Forest",
	"tree","One of the trees in this wood.  It seems to stare at you!",
	"trees","The trees in this wood appear to have a mind of their own",
	"moss","A green grey moss that grows here in abundance",
	"growths","Horrible slimy things that cover the trees",
	"roots","These roots seems to be trying to trip you up!",
	"mist","Thin wispy stuff, lacking any real substance",
	"canopy","It is too far above you to see anything clearly",
	"undergrowth","Typical woodland undergrowth",
	"scrub","Its wiry existence litters the floor",
	"shadows","Rather inconsistent things.  You can't really see anything",
	"leaves","The forest is full of them, hardly surprising really"

	});
  }
  ::reset(flag);
#if 0
  replace_program("room/room");
#endif

}
init()
{
  ::init();
  add_action("do_climb","climb");
}

int do_climb(string arg)
{
   if(arg !="tree" && arg !="trees")
   {
    notify_fail("The only things to climb around here are trees!\n");
    return 0;
   }
   write("The tree seems to laugh as you slide down its trunk to the floor\n");
   return 1;
}
