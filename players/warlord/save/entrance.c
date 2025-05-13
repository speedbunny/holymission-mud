/*
	Entrance to the Emerald MUD Inns
	by Kriton@Emerald MUD
*/

#include "apartment.h"

inherit ROOM;

void create()
{
  room::create();
  set_short("Entrance to the Emerald MUD Inns");
  set_properties(([ "light":2, "indoors":1, "no magic":1, "no attack":1 ]));
  set_long(
"   Welcome to the spacious Emerald MUD Inn located in the wonderful city\n"
"of Tear!  We always have room for more guests!  If you wish to get a room\n"
"here at the Inn, you may <rent room>, which will reserve a spot for you\n"
"in a room for one month's time.  You can also extend your stay by paying\n"
"for additional months by typing <pay rent>.  If you wish to see when your\n"
"next payment is due, type <pay status>.  Also, to see what the current\n"
"rates are, type <pay cost>.\n"
"   Once you have rented a room, simply type <enter room>.  Also, if you are\n"
"here to visit a spouse, type <visit spouse>, or, if you are here just to\n"
"visit a friend and have that friend's permission you can <visit [name]>."
  );
  set_exits(([
  "east" : "/d/tear/roads/south_main03",
  ]));
}

void init()
{
  room::init();
  add_action("enter_room", "enter");
  add_action("visit_room", "visit");
  add_action("pay_rent", "pay");
  add_action("rent_room", "rent");
}

int enter_room(string str)
{
  mixed ret;
  
  if(str != "room")
  {
    write("Enter room perhaps?");
    return 1;
  }
  if(intp(ret = APARTMENT_D->find_apartment( getuid(this_player()) )))
  {
    switch(ret)
    {
      case -1: write("You don't even have a room here!"); break;
      case -2: write("Your rent is overdue.  You must pay it first."); break;
      default: printf("Unknown error #%d.  Tell Kriton.\n", ret);
    }
    return 1;
  }
  if(!objectp(ret))
  {
    write("You notice that something is wrong when you try and enter your "
      "room.  Perhaps you should tell Kriton.");
    return 1;
  }
  write("You go up to your room.");
  this_player()->move_player(ret, "into "+this_player()->query_possessive()+
    " room");
  return 1;
}

int visit_room(string str)
{
  mixed ret;
  int ap;
  
  if( !str ) return notify_fail("Whom did you wish to visit?\n");
  if((str = convert_name(str)) == getuid(this_player()))
    return notify_fail("Visit yourself.  Just use <enter room>.\n");
  if(str == "spouse")
  {
    if(!(str = this_player()->query_married()))
      return notify_fail("You're not even married!\n");
    str = convert_name(str);
    ap = 1;
  }
  if(intp(ret = APARTMENT_D->find_apartment( str )))
    return notify_fail("That person does not have a room here or has "
    "failed to pay his or her rent.\n");
  if(!objectp(ret))
    return notify_fail("There was an error while attempting to load that "
    "person's room.\n");
  if(!ap && !ret->has_access( getuid(this_player()) ))
    return notify_fail("You are not on that person's guest list.\n");
  this_player()->move_player(ret, "into an room");
  return 1;
}

int pay_rent(string str)
{
  class apartment_rec ap;
  
  if(str != "rent" && str != "status" && str != "cost")
    return notify_fail("Pay rent perhaps?\n");
  if(!APARTMENT_D->has_apartment( getuid(this_player()) ))
    return notify_fail("You don't even have a room here.\n");
  if(str == "cost")
  {
    printf("The current rent price is %d gold/month.\n", RENT_MONEY);
    return 1;
  }
  ap = APARTMENT_D->load_apartment( getuid(this_player()) );
  if(str == "status")
  {
    printf("Next rent payment is due on %s.\n", ctime(ap->rent_due)[0..9]);
    return 1;
  }  
  if((int)this_player()->query_money() < RENT_MONEY)
    return notify_fail("You don't have the money to pay rent right now.\n");
  ap->rent_due += ONE_MONTH;
  this_player()->add_money(-RENT_MONEY);
  if(ap->rent_due <= time())
    write("That did help, but you are still behind in rent.");
  else
    printf("The next rent is now due at %s.\n", ctime(ap->rent_due)[0..9]); 
  APARTMENT_D->save_apartment(getuid(this_player()), ap);
  return 1;
}

int rent_room(string str)
{
  class apartment_rec ap;
  
  if(str != "room") return notify_fail("Rent room perhaps?\n");
  if(APARTMENT_D->has_apartment( getuid(this_player()) ))
    return notify_fail("You already HAVE a room here.\n");
  if((int)this_player()->query_money() < RENT_MONEY)
    return notify_fail("You don't have the money needed to rent a room.\n");
  ap = APARTMENT_D->load_apartment( getuid(this_player()) );
  ap->rent_due = time() + ONE_MONTH;
  write("You hand over your money and the manager gives you the key to "
    "your room.  You may now <enter room>.");
  this_player()->add_money(-RENT_MONEY);
  APARTMENT_D->save_apartment(getuid(this_player()), ap);
  return 1;
}
