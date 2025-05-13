#include "/players/skeeve/area.h"

inherit "room/room";

object druid;

#define MAZE_SIZE 25

int chamber,chapel;
int *maze_dirs,*maze_monsters;

object satan,devil,mummy,zombie;

reset(arg) {
  object druid;
  if (!arg) {
    set_light(1);
    short_desc = "Chapel";
    long_desc = "This is the chapel of the holy druid.\n";
    smell="";
    items = ({
        "walls", "The walls are of cracked terra cotta",
        "floor", "The floor is covered with an stony inlay",
        "mirror","@@mirror@@"
      });
    maze_dirs = allocate(MAZE_SIZE);
    maze_monsters = allocate(MAZE_SIZE);
  }
  make_maze();
  druid = CASTLE->add_monster("druid",this_object());
  if (environment(druid) != this_object()) 
    move_object(druid,this_object());
}

init () {
  ::init();
  add_action("new_rooms","new_rooms");
}

new_rooms() {
  int i;
  object room;
  for (i=0;i<25;i++)
    if (room = find_object(MAZE+"maze"+i)) destruct(room);
  return 1;
}

mirror() {
  int i,j;
  string str;

  str = "A plan of the holy maze:\n";

  for (i=4;i>=0;i--) {
/* 1. line */
    for (j=0;j<5;j++) {
      str += (maze_dirs[i*5+j] & 33) ? "+-   -" : "+-----";
    }
    str += "+\n";
/* 2. line */
    for (j=0;j<5;j++) {
      str += "|";
      str += (maze_monsters[i*5+j] & 1) ? "S" : " ";
      str += (maze_monsters[i*5+j] & 2) ? "D" : " ";
      str += (maze_monsters[i*5+j] & 4) ? "M" : " ";
      str += (maze_monsters[i*5+j] & 8) ? "Z" : " ";
      str += (maze_monsters[i*5+j] & 16) ? "V" : " ";
    }
    str += "|\n";    
/* 3. line */
    for (j=0;j<5;j++) {
      str += (maze_dirs[i*5+j] & 4) ? " " : "|";
      /* monster */
      str += (maze_monsters[i*5+j] & 32) ? "Sk" : "  ";
      str += ((find_object(MAZE+"maze"+(i*5+j))) ? "*" : " ");
      str += (maze_monsters[i*5+j] & 64) ? "Sp" : "  ";
    }
    str += "|\n";
/* 4. line */
    for (j=0;j<5;j++) {
      str += "|";
      /* monster */
      str += (maze_monsters[i*5+j] & 128) ? "Sn" : "  ";
      str += (maze_monsters[i*5+j] & 256) ? "B" : " ";
      str += (maze_monsters[i*5+j] & 512) ? "S" : " ";
      str += (maze_monsters[i*5+j] & 1024) ? "F" : " ";
    }
    str += "|\n";
  }
  for (j=0;j<5;j++)
    str += (maze_dirs[j] & 24) ? "+-   -" : "+-----";
  str += "+\n";
  return(str);
}

make_maze() {
  int i, new, old, count;
  int neightbours;
  neightbours = allocate(MAZE_SIZE);
  
  maze_dirs[new = chamber = random (5)] |= 16;/* passage to the chamber */
  count = 0;

  while (new>=0) {
    /* the new neightboors */
    if ((new >  4) && !maze_dirs[new-5]) {
      neightbours[count++]=new-5;
      maze_dirs[new-5] |=64;
    }
    if ((new < 20) && !maze_dirs[new+5]){
      neightbours[count++]=new+5;
      maze_dirs[new+5] |=64;
    }
    if ((new%5   ) && !maze_dirs[new-1]){
      neightbours[count++]=new-1;
      maze_dirs[new-1] |=64;
    }
    if ((new%5!=4) && !maze_dirs[new+1]){
      neightbours[count++]=new+1;
      maze_dirs[new+1] |=64;
    }

    if (count>0) {
      for (new = neightbours[i=random(count--)];i<count;i++)
         neightbours[i] = neightbours[i+1];
    
      /* make the connetion to the ready maze */
      i = random(4);                    /* the old field is in the */
      while (((i==0) && ((new>19)  || !(maze_dirs[new+5]&63)))    /* north */
           ||((i==3) && ((new<5)   || !(maze_dirs[new-5]&63)))    /* south */
           ||((i==1) && ((new%5==4)|| !(maze_dirs[new+1]&63)))    /* east  */
           ||((i==2) && ((!(new%5))|| !(maze_dirs[new-1]&63)))) { /* west  */
        i = (i+1)%4;
      }
      switch (i) {
        case 0: old = new+5; break;
        case 1: old = new+1; break;
        case 2: old = new-1; break;
        case 3: old = new-5; break;
      }
      maze_dirs[new] = maze_dirs[new] | (1<<i);     /* (i,f): (0,1), (1,2), (2,4), (3,8) */
      maze_dirs[old] = maze_dirs[old] | (1<<(3-i));
    } else
      new = -1;
  }
  
  maze_dirs[chapel =20+random(5)] |= 32;   /* passage to the chapel */
  
  /* monsters */
  for (new=0;new<MAZE_SIZE;new++) {
    object room;
    if ( !(room=find_object(MAZE+"maze"+new)) || !present("mmonster",room) )
      maze_monsters[new]=1<<(random(7)+4);
  }
  if (!satan){
    new = random (MAZE_SIZE);
    maze_monsters[new]|=1;
  }
  if (!devil){
    new = random (MAZE_SIZE);
    maze_monsters[new]|=2;
  }
  if (!mummy){
    new = random (MAZE_SIZE);
    maze_monsters[new]|=4;
  }
  if (!zombie){
    new = random (MAZE_SIZE);
    maze_monsters[new]|=8;
  }
  update_rooms();
}

update_rooms() {
  int i;
  object room;
  for (i=0;i<25;i++)
    if (room = find_object(MAZE+"maze"+i)) {
      room->set_dir(query_maze_dirs(i));
      if (maze_monsters[i]){
        room->set_monster(maze_monsters[i]);
        maze_monsters[i]=0;
      }
      update_players(room);
    }
  if (room = find_object(MAZE+"chamber")) {
    room->set_dir(query_maze_dirs(25));
    update_players(room);
  }
  dest_dir = query_maze_dirs(26);
  update_players(this_object());
}

update_players(room) {
  object inv;
  int i;
  inv = all_inventory(room);
  for (i=0;i<sizeof(inv);i++) {
    transfer(inv[i],MAZE+"beetween");
    transfer(inv[i],room);
  }
}

set_maze(nr,room) {
  room->set_dir(query_maze_dirs(nr));
  if (nr<MAZE_SIZE) {  /* monsters */
  room->set_monster(maze_monsters[nr]);
  maze_monsters[nr]=0;
  }
}

query_maze_dirs(nr) {
  string dir;
  int d;
  dir = ({});
  if (nr<25) {
    d = maze_dirs[nr];
    if (d & 1)   dir += ({MAZE+"maze"+(nr+5),"north"});
    if (d & 2)   dir += ({MAZE+"maze"+(nr+1),"east"});
    if (d & 4)   dir += ({MAZE+"maze"+(nr-1),"west"});
    if (d & 8)   dir += ({MAZE+"maze"+(nr-5),"south"});
    if (d & 16)  dir += ({MAZE+"chamber","south"});
    if (d & 32)  dir += ({MAZE+"chapel","north"});
  } else if (nr==25) 
    dir = ({MAZE+"maze"+chamber,"north"});/*,LAND+"cave","up"*/
  else  dir = ({MAZE+"maze"+chapel,"south"});
  return dir;
}
