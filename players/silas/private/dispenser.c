/* Dispenser template
   Use this instead of specific files (Alphanet will LOVE you)
   usage: clone a copy of this file in the rooms initial reset
          the following functios set it up:


   set_name(string)               name of dispenser
   set_alias(string)              alt name of dispenser
   set_read(string)               text written on dispenser
   set_long(string)               long description of dispenser
   set_short(string)              short description of dispenser
   set_plate_alias(string)        name of the part of the dispenser
                                  which has the text on it (eg label)

           and these set up the items to sell:


   set_i_clone(array of strings)  array with the files from which each
                                  item will be cloned (eg /obj/drug, 
				                          /obj/armour)
   set_i_calls(array of arrays,
               array of arrays)   first array has one array for each 
	                          item sold.  The items in the contained
				  arrays are the names of the functions
				  which must be called in the sold item
				  to set it up (eg set_weight, set_name)

				  The second array holds one array for
				  each item, in this case holding the
				  arguments for the calls in the first
				  array.  If there is more than one
				  argument for a function then the 
				  argument should also be an array.

   set_i_short(array of strings)  array of the short descriptions of items
   set_i_name(array_of_strings)   array of the names of items
   set_i_long(array_of_strings)   array of the long descriptions of items
   set_i_price(array_of_strings)  array of the prices of items
*/

/* EXAMPLE !!

reset(var) {
  object thing;
  if (var) return;
  set_light(1);
  short_desc = "Arcade Balcony";
  long_desc = 
    "Stairs lead down to the lower floor from here.\n";
  dest_dir = 
    ({
      "players/bodkin/arcade/c_balc", "north",
      "players/bodkin/arcade/by_lift7", "down",
    });
  thing=clone_object("players/bodkin/obj/dispenser");
  thing->set_name("dispenser");
  thing->set_short("Drug Dispenser");
  thing->set_long("A glowing blue cabinet covered in deep-purple runes,\n"+
		  "on the front are some small, pink buttons.  And a notice.\n"+
		  "The buttons are labeled:\n\n");
  thing->set_alias("cabinet");
  thing->set_screed("These drugs are provided \"as is\" and at the\n"+
		    "users risk.  Bodkin provides no warranty whatsoever\n"+
		    "and accepts no responsibility for the users well-being.\n"+
		    "In particular in regard to loss of memory, liberty,\n"+
		    "happiness or LIFE.\n");
  thing->set_plate_alias("notice");
  thing->set_i_clone(({"obj/drug","obj/drug",
			 "obj/drug","obj/drug",
			 "obj/drug","obj/drug"}));
  thing->set_i_name(({"weed","pill","codine","pill","dust","star"}));
  thing->set_i_short(({"Happy Weed","Electronic Blue",
			 "2-methyl-3,3-dichloro-codine",
			 "Normality Pill","Angle Dust","Chaos Star"}));
  thing->set_i_long(({"A handfull of grey/silver leaves.\n",
			"A blue pill with traces of inner\n"+
			  "circuitry showing through.\n",
			  "A vial of clear liquid.\n",
			  "A plain white pill with \"n\" stamped on each side.\n",
			  "Finely ground geometry.\n",
			  "A pentagonal crystal of pure chaos.\n"}));
  thing->set_i_price(({25,75,125,50,250,350}));
  thing->set_i_calls(({({"set_drink_command","set_weight","set_strength",
			   "set_alias","set_drinking_mess",
			   "set_drinker_mess"}),
			 ({"set_drink_command","set_weight","set_strength",
			     "set_alias","set_drinking_mess",
			     "set_drinker_mess"}),
			 ({"set_drink_command","set_weight","set_strength",
			     "set_alias","set_drinking_mess",
			     "set_drinker_mess","set_empty_container"}),
			 ({"set_drink_command","set_weight","set_strength",
			     "set_alias","set_drinking_mess",
			     "set_drinker_mess"}),
			 ({"set_drink_command","set_weight","set_strength",
			     "set_alias","set_drinking_mess",
			     "set_drinker_mess"}),
			 ({"set_drink_command","set_weight","set_strength",
			     "set_alias","set_drinking_mess",
			     "set_drinker_mess"})}),
		     ({({"chew",1,10,"leaves"," grins broadly.\n",
			   "You always *knew* life was good.\n"}),
			 ({"eat",1,20,"blue"," is covered in blue sparks.\n",
			     "You're glad to be Cray.\n"}),
			 ({"drink",1,30,"vial","`s mind comes out of his ear.\n",
			   "You decide you'll just leave your body here "
			  +"for a while.\n","vial"}),
                         ({"eat",1,10,""," becomes more ordinary.\n",
			   "You feel a whole lot saner!\n"}),
			  ({"sniff",1,40,"angle"," gets a little fractal"
			   +" around the edges.\n",
			    "You're a whole lot less square now!\n"}),
		          ({"eat",1,50,"crystal"," gets random.\n",
			    "You realize that rules just don't apply to you!\n"})}));
  move_object(thing,this_object());
}

This will install a drugs dispenser in this object
Please do not copy this exactly */


string long_desc,short_desc,name;
string alias,plate_screed;
string plate_alias;
int num_items;

int i_price;
string i_name,i_short,i_long;
string i_clone;
string i_calls,i_call_args;

init() {
  add_action("press","press");
  add_action("press","push");
  if (plate_screed) {
    add_action("read","read");
    add_action("look","look");
  }
}

reset(arg) {
  if (arg)
    write("The "+name+" buzzes quietly for a second.\n");
}

long() {
  int num;
  write(long_desc);
  for (num=0;num < num_items;num++) 
    write(num+1+" > "+i_short[num]+" : "+i_price[num]*2+"\n");
  write("\n");
}

short() { return short_desc ; }

query_weight() {
  return 50;
}

id(arg) {
  return arg == name || arg == alias;
}

/* setup inventory */

set_i_clone(vector) {
  i_clone=vector;
  num_items=sizeof(i_clone);
}

set_i_calls(vector1,vector2) {
  i_calls=vector1;
  i_call_args=vector2;
}

set_i_short(vector) {
  i_short=vector;
}

set_i_name(vector) {
  i_name=vector;
}

set_i_long(vector) {
  i_long=vector;
}

set_i_price(vector) {
  i_price=vector;
}

/* selling routines */

press(arg) {
  object obj;
  string b;
  int num;
  if (!arg)
    return 0;
  if (sscanf(arg,"button %s",b) != 1)
    b = arg;
  if (sscanf(b,"%d",num)!=1)
    return 0;
  if ((num > num_items)||(num<1))
    return 0;
  say(this_player()->query_name()+" presses button "+num+"\n");
  write("You press button "+num+"\n");
  sell(num-1);
  return 1;
}

sell(num) {
  object obj;
  int n,m;
  if (!can_afford(i_price[num]*2))
    return;
  obj=clone_object(i_clone[num]);
  obj->set_name(i_name[num]);
  obj->set_short(i_short[num]);
  obj->set_long(i_long[num]);
  obj->set_value(i_price[num]);
  write("The "+name+" hums.\n");
  say("The "+name+" hums.\n");
  for (n=0;n < sizeof(i_calls[num]);n++) {
    if (pointerp(i_call_args[num][n])) {
      m=sizeof(i_call_args[num][n]);
      if ( m == 2) {
	call_other(obj,i_calls[num][n],i_call_args[num][n][0]
		   ,i_call_args[num][n][1]);
      }
      else if ( m == 3)
	call_other(obj,i_calls[num][n],i_call_args[num][n][0]
		   ,i_call_args[num][n][1]
		   ,i_call_args[num][n][2]);
      else if ( m == 4)
	call_other(obj,i_calls[num][n],i_call_args[num][n][0]
		   ,i_call_args[num][n][1]
		   ,i_call_args[num][n][2]
		   ,i_call_args[num][n][3]);
    } else
	call_other(obj,i_calls[num][n],i_call_args[num][n]);
  }
  give(obj,obj->query_weight(),num,);
  return 1;
}

read(arg) {
  if (!arg)
    return 0;
if ((!id(arg))&&(arg != plate_alias))
    return 0;
  write(plate_screed);
  return 1;
}

can_afford(cost) {
  int chance;
  if (this_player()->query_money() < cost) {
    tell_room(environment(),"A gong sounds.\n"+this_player()->query_name()+" is too poor!\n");
    return 0;
  }
  chance=random(5);
  return 1;
}

give(obj,weight,num) {
  write("The dispenser hands you a "+i_name[num]+".\n");
  this_player()->add_money(-i_price[num]*2);
  if (this_player()->add_weight(weight)) {
    move_object(obj,this_player());
    say(this_player()->query_name()+" buys a "+i_name[num]+".\n");
  } else {
    write("Which is too heavy and you drop it.\n");
    move_object(obj,environment());
    say(this_player()->query_name()+" can't carry his "+i_name[num]+".\n");
  }
}

look(arg) {
  if (!arg)
    return 0;
  if (arg != "at "+plate_alias)
    return 0;
  read(plate_alias);
  return 1;
}

/* setup own appearance */

set_screed(arg) {
  plate_screed=arg;
}

set_name(n) {
    name = n;
}

set_alias(n) { alias = n; }

set_read(str) {
    plate_screed=str;
}

set_long(arg) {
  long_desc=arg;
}

set_short(arg) {
  short_desc=arg;
}

set_plate_alias(arg) {
  plate_alias=arg;
}
