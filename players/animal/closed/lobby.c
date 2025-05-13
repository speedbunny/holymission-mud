inherit "room/room";
 
#define MINS 1
 
object note,sign;
int passage_open;
string renter,bring;
int full,ttimer;
status debug;
 
query_bring(i){return bring[i];}
query_renter(i){return renter[i];}
query_ttimer(i){return ttimer[i];}
 
set_debug(value) { debug = value; return debug; }
set_bring(value,i){bring[i]=value;}
set_renter(value,i){renter[i]=value;}
set_ttimer(value,i){ttimer[i]=value;}
 
init() 
{
::init();

  passage_open = 0;
 
  add_action("get_a_cabin", "rent");
  add_action("search","search");
   add_action("north","north");
  add_action("enter_cabin", "enter");
  add_action("enter_cabin", "cabin");
  add_action("list_cabins", "renters");
  add_action("list_cabins", "cabins");
  add_action("list_cabins", "rentals");
}
 
reset(arg) 
{
::reset();
  if(arg) return;
  
  set_light(1);
  
  short_desc = "The Lobby of Cabin Villiage";
  
  long_desc =
 
    "Cabin Lobby\n\n"+
    "\tThis is the lobby of Cabin Villiage, a first class\n" +
    "\tcabin resort.  In the Village you can rent cabins\n" +
    "\tfor a LOW LOW price of 1 gold / "+MINS+" minutes of time!!!\n" +
    "\tWHAT A BARGAIN!!! One of the advantages is that you can\n"+
    "\tleave your VALUABLE goods here, and NO ONE can get it but\n"+
    "\tyou!! COOL EH?  You can also 'bring' friends to your cabin\n" +
    "\tand have a private party!!\n"+
    "\tTo enter your cabin type: enter <your_number>\n" +
    "\tRead the note on the wall for more information.\n\n";
  dest_dir =
    ({
      "players/animal/shops/shop_street4","south"
      });
  
  if(!note)
    {
      note=clone_object("players/animal/obj/condo_note");
      transfer(note,this_object());
    }
  
  renter=allocate(15);
  ttimer=allocate(15);
  renter[0]="Animal";
  bring=allocate(15);
 
  if(sign)
    destruct(sign);
  sign=clone_object("players/animal/obj/space");
  transfer(sign,"players/animal/shops/shop_street3");
  call_out("timer",60);
}
 
 
list_cabins()
{
  int i;
  string inv;
 
  write("Cabin Whose \tTime  \tInviting\n");
/*
  write("0     Animal\tLONG  \tcool people\n");
*/
  for(i=1;i<15;i++)
    if(renter[i])
      {
if(bring[i])
       inv=bring[i];
          else
       inv="-";
  write(i+"     "+renter[i]+"\t"+ttimer[i]+" M\t"+inv+"\n");
      }
  return 1;
}
 
 
get_a_cabin(str)
{
  int i,vacant,tyme;
  string name,logtext;
 
  if(this_player()->query_invis() || this_player()->query_npc())
    {
      write("The Landlord sneers at you!\n");
      say("The Landlord sneers.\n",this_player());
      return 1;
    }
 
  if(!str || !sscanf(str,"%d",tyme) || (tyme<1))
    {
      write("Usage:rent time\n");
      write("      time is in "+MINS+" minutes. It is also the cost for the cabin.\n");
      return 1;
    }
 
  if(this_player()->query_money()<tyme)
    {
      write("Get more cash, PUNK!\n");
     say("The Landlord yells at "+this_player()->query_name()+".\n");
      return 1;
    }
 
  name=this_player()->query_name();
 
/*
  if(name=="Animal")
    {
      write("The Landlord shakes your hand.\n");
      say("The Landlord shakes Animal's hand.\n");
      return 1;
    }
*/
 
  for(i=0;i<15;i++)
    if(renter[i]==name)
      {
          this_player()->add_money(-tyme);
          tyme*=MINS;
          ttimer[i]+=tyme;
          write("You now have the cabin for "+ttimer[i]+" minutes.\n");
          say(name+" now has the cabin for "+ttimer[i]+" minutes.\n");
          return 1;
      }
 
  if(full)
    {
      write("Sorry man, there is a HUGE cabin shortage, try back later!\n");
      return 1;
    }
 
  vacant=0;
  for(i=0;i<15;i++)
    if(!renter[i])
      {
          vacant=i;
          break;
      }
 
	if(vacant == 0) 
	   {
		write("That is Animal's personal cabin!\n");
		full = 1;
		write("The cabins must be all gone!\n");
		return 1;
	   }

  if(vacant==14)
    {
      write("Whew! You got the last cabin for rent!\n");
      destruct(sign);
      sign=clone_object("players/animal/obj/nospace");
      transfer(sign,"players/animal/shops/shop_street3");
      full=1;
    }
 
  this_player()->add_money(-tyme);
  renter[vacant]=name;
  tyme*=MINS;
  ttimer[vacant]=tyme;
    write("You got Cabin #"+vacant+" for "+tyme+" minutes of time.\n");
  write("You may enter it by typing: enter "+vacant+".\n");
  logtext = name+" rented number "+vacant+" for "+tyme+" minutes on "+ctime(time())+"\n";
  say(logtext);
  write_file("/players/animal/shops/cabin",logtext);
  return 1;
}
 
timer()
{
  int i,thrown;
  string cabin;
 
  call_out("timer",60);
  for(i=1;i<15;i++)
    if(renter[i])
      {
	if(debug)
	if(find_player("animal"))
	tell_object(find_player("animal"),"Timer was called.\n");
          ttimer[i]--;
          if(ttimer[i]==0)
  {
    say("Cabin number "+i+" is now free.\n");
     if(find_player(lower_case(renter[i])))
	if(!environment(find_player(lower_case(renter[i])))->query_cabin())
	tell_object(find_player(lower_case(renter[i])),"Landord tells you: Your Cabin is no longer paid for BUB!\n");
    renter[i]=0;
    bring[i]=0;
    if(full)
      {
          full=0;
          destruct(sign);
          sign=clone_object("players/animal/obj/space");
          transfer(sign,"players/animal/shops/shop_street3");
      }
    thrown=0;
    cabin="/players/animal/shops/condos/"+i;
    cabin->clean_up();
    thrown=throw_out(cabin);
    if(thrown==0)
      say("The Landlord smirks.\n");
    else
      if(thrown==1)
say("You hear the sound of an object being tossed out, the cabin had something in it still.\n");
      else
if(thrown<5)
  say("You hear several objects being tossed. That cabin had a lot of stuff in it.\n");
else
  say("You hear a LOT of noise coming from that cabin.\n");
  }
      }
  return 1;
}
 
throw_out(from)
{
  object ob,next;
  int thrown;
 
  tell_room(from,"Your time is up!! Get out of the cabin!!!\n" +
                 "FLING! You are thrown out into the street.\n");
 
  ob=first_inventory(from);
  thrown=0;
  while(ob)
    {
      thrown++;
      next=next_inventory(ob);
      if(living(ob))
        transfer(ob,"players/animal/shops/shop_street3");
      else
        transfer(ob,"players/animal/shops/store");
      ob=next;
    }
  return thrown;
}
 
 
enter_cabin(str)
{
  string name;
  int cabin;
 
  if(!str || !sscanf(str,"%d",cabin) || (cabin<0))
    {
      write("Enter which cabin?? (give cabin number)\n");
      return 1;
    }
 
  name=this_player()->query_name();
  /* P.S. Changed by Ethereal Cashimor. It's still not quite good now,
     but still, it works if you're not invisible or a ghost. Don't
     change your pretitle while having the cabin though... 030393 */
 
  if(cabin>14 || (name != renter[cabin] && name != bring[cabin]) 
	|| ( cabin == 0 && name != "Animal"))
    {
      write("Not your cabin.\n");
      return 1;
    }
 
  if(cabin>0)
    if(ttimer[cabin]<5)
      write("Your time is almost gone on this cabin BUB!!\n");
    else
      write("This cabin has "+ttimer[cabin]+" minutes left.\n");
  this_player()->move_player("for cabin "+cabin+"#players/animal/shops/condos/"+cabin);
  return 1;
}

search(str){
    object ob;
    if (!str) str = "room";
    if (str=="room") {
     if(random(100) > 60) {
   write("You find a door leading north!\n");
     say(call_other(this_player(),"query_name") +
     " finds a door leading north.\n");
        passage_open=1;
    }else{
     write("You find nothing unusual.\n");
    return 1;
     }
     return 1;
   }
}

long(){
     ::long();
    if (passage_open) write("There is a door open leading north.\n");
}
 
north(){
    if (!passage_open) return 0;
    call_other(this_player(),"move_player","north#players/animal/shops/garbagebin");
    return 1;
}

start_t()  {
		call_out("timer",2);
		write("Timer started.\n");
		return 1;
}
