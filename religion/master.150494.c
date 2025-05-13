/* Patience, May 1993:
   added the religon ZEN & AMATERASU:
   Amaterasu is a shinto-religion, i use if for my guild:
      the files are in: ../ezo/coast/jingu.c, ../ezo/coast/puri_check.c

   Patience, May 1993:
   removed ZEN, it isn't needed any longer.
   Moonchild 050793 removed the bug messages, they weren't bugs usually.
*/

inherit "room/room";

string religions,prays;
int alignments;

/* In the reset the main arrays are set-up. religions contains all the
   different religions that there are at the moment. Alignment indicates if
   there are alignment restrictions to the specified religion. 0 means no
   restrictions, 1 means only good characters, 2 means only evil characters
   and 3 means only neutral characters. prays contains the files in which
   do_pray is being called if the character prays. */
reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Religion Master";
    long_desc="This is the religion master. I hope you like it...\n";
    set_light(1);
    religions=({"Iluvatar","Kari","Amaterasu"});
    alignments=({0,1,0});
    prays=({"religion/master","religion/master","religion/master"});
  }
}

init() {
 ::init();
 add_action("dump_it","dump");
}

dump_it() {
int i;

  for(i=0;i<sizeof(religions);i++) {
    write(religions[i]+"\t"+prays[i]+"\t"+alignments[i]+"\n");
  }
  return 1;
}

/* This is a dummy function. Direct the do_pray to this file to have a pray
   that does nothing in particular. */
do_pray(belief,str) {
int where;

  if(belief==0) {
    notify_fail("But you're not following a god!\n");
    return 0;
  }
  where=member_array(belief,religions);
  if(where==-1) {
#if 0
    notify_fail("Bug #1: Contact the gods!\n");
#endif
    return 0;
  }
  if(!prays[where]) {
#if 0
    notify_fail("Bug #2: Contact the gods!\n");
#endif
    return 0;
  }
  return prays[where]->pray_it(str);
}

/* Query_ok checks if the alignment of the character matches his/her religion.
   If this function returns 0 than the alignment does NOT match the religion
   and that means the character is sinful. */
query_ok(belief,align) {
int where;

  if(belief==0) return 1;
  where=member_array(belief,religions);
  if(where==-1) return 2;
  switch(alignments[where]) {
    case 0: return 3;
    case 1: if(align>100) return 3; break;
    case 2: if(align<-100) return 3; break;
    case 3: if((align<100)&&(align>-100)) return 3;
  }
}
 
pray_it(str) {
  write("You pray.\n");
  say(this_player()->query_name()+" prays.\n");
  return 1;
}
