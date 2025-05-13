#define NAME "Axlrose"
#define DEST "/players/axlrose/workroom"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

inherit "/room/room";

#define DEBUG

mapping good,evil,in_use;

mapping query_in_use() {
  return in_use;
}

void add_good_general(string file,string *locations) {
  if(!good)
    good=([]);
  good[file]=locations;
}

void add_evil_general(string file,string *locations) {
  if(!evil)
    evil=([]);
  evil[file]=locations;
}

void select_generals() {
  string *old,*e,*g,*list,*arr;
  int num,i,es,gs,rnd;
  object ob;

  if(!in_use)
    in_use=([]);

// This line selects the number of generals to clone... Can be anywhere
// between 0 and 6, although the chance of there being 0 or 6 is much
// less than the chance of there being 1, 2, 3, 4 or 5.
  num=(random(17)+2)/3;

#ifdef DEBUG
  tell_room(this_object(),"Going to select "+num+" generals this reset.\n");
#endif

// This code checks to see how many of the generals are left from the
// last allocation, and reduces the number selected accordingly.
  old=m_indices(in_use);
  for(i=0;i<sizeof(old);i++) {
    ob=find_object(in_use[old[i]]);
    if(ob && environment(ob))
      num--;
    else
      in_use=m_delete(in_use,old[i]);
  }

// If we already have the selected number of generals in the area from
// the last reset(), we don't want to add any more, so we stop here.
  if(num<=0)
    return;

// Now we select the new generals for this reset...
  g=m_indices(good);
  gs=sizeof(g);
  e=m_indices(evil);
  es=sizeof(e);

  for(i=0;i<num;i++) {
    list=m_values(in_use);
    if(!random(2)) {
      rnd=random(gs);
      while(member_array(g[rnd],list)!=-1)
        rnd=random(gs);
      arr=good[g[rnd]];
      in_use[arr[random(sizeof(arr))]]=g[rnd];
    }
    else {
      rnd=random(es);
      while(member_array(e[rnd],list)!=-1)
        rnd=random(es);
      arr=evil[e[rnd]];
      in_use[arr[random(sizeof(arr))]]=e[rnd];
    }
  }
}

void load_general(string room) {
  string general;

  general=in_use[room];

  if(general)
    general->mobilize(room);
}

int test() {
  string *gen,*rooms;
  int i;

  gen=m_values(in_use);
  rooms=m_indices(in_use);
  write("The following generals were initialized this reset:\n\n");
  for(i=0;i<sizeof(gen);i++)
    printf("%-30s -> %s\n",gen[i],rooms[i]);
  return 1;
}

  
int enter(string str) {
  if(!str || !id(str))
    return 0;
  else {
    this_player()->move_player("into the castle#/players/axlrose/castle");
    return 1;
  }
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="Castle of " + NAME;
    long_desc="This is the "+short_desc+".\n"+NAME
+" is a rather new wizard, but it is an amazing castle just the same. \
However, the gates are closed.\n";
    items=({ 
      "castle","@@short",   /* we need that to get the 'castle' id */
    });
    move_object(this_object(), DEST);

// This is the code to set all the possible generals and their random
// locations:
    add_good_general("/players/axlrose/monster/good_gen1",({
      "/players/axlrose/room/good_gen1_room1",
      "/players/axlrose/room/good_gen1_room2",
      "/players/axlrose/room/good_gen1_room3",
      "/players/axlrose/room/good_gen1_room4",
    }));
    add_good_general("/players/axlrose/monster/good_gen2",({
      "/players/axlrose/room/good_gen2_room1",
      "/players/axlrose/room/good_gen2_room2",
      "/players/axlrose/room/good_gen2_room3",
      "/players/axlrose/room/good_gen2_room4",
    }));
    add_good_general("/players/axlrose/monster/good_gen3",({
      "/players/axlrose/room/good_gen3_room1",
      "/players/axlrose/room/good_gen3_room2",
      "/players/axlrose/room/good_gen3_room3",
      "/players/axlrose/room/good_gen3_room4",
    }));
    add_good_general("/players/axlrose/monster/good_gen4",({
      "/players/axlrose/room/good_gen4_room1",
      "/players/axlrose/room/good_gen4_room2",
      "/players/axlrose/room/good_gen4_room3",
      "/players/axlrose/room/good_gen4_room4",
    }));
    add_good_general("/players/axlrose/monster/good_gen5",({
      "/players/axlrose/room/good_gen5_room1",
      "/players/axlrose/room/good_gen5_room2",
      "/players/axlrose/room/good_gen5_room3",
      "/players/axlrose/room/good_gen5_room4",
    }));
    add_evil_general("/players/axlrose/monster/evil_gen1",({
      "/players/axlrose/room/evil_gen1_room1",
      "/players/axlrose/room/evil_gen1_room2",
      "/players/axlrose/room/evil_gen1_room3",
      "/players/axlrose/room/evil_gen1_room4",
    }));
    add_evil_general("/players/axlrose/monster/evil_gen2",({
      "/players/axlrose/room/evil_gen2_room1",
      "/players/axlrose/room/evil_gen2_room2",
      "/players/axlrose/room/evil_gen2_room3",
      "/players/axlrose/room/evil_gen2_room4",
    }));
    add_evil_general("/players/axlrose/monster/evil_gen3",({
      "/players/axlrose/room/evil_gen3_room1",
      "/players/axlrose/room/evil_gen3_room2",
      "/players/axlrose/room/evil_gen3_room3",
      "/players/axlrose/room/evil_gen3_room4",
    }));
    add_evil_general("/players/axlrose/monster/evil_gen4",({
      "/players/axlrose/room/evil_gen4_room1",
      "/players/axlrose/room/evil_gen4_room2",
      "/players/axlrose/room/evil_gen4_room3",
      "/players/axlrose/room/evil_gen4_room4",
    }));
    add_evil_general("/players/axlrose/monster/evil_gen5",({
      "/players/axlrose/room/evil_gen5_room1",
      "/players/axlrose/room/evil_gen5_room2",
      "/players/axlrose/room/evil_gen5_room3",
      "/players/axlrose/room/evil_gen5_room4",
    }));
  }
  select_generals();
}

void init() {
  ::init();
  add_action("enter","enter");
  add_action("test","test");
}
