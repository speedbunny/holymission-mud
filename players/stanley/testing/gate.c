/* gate is either "The gate is open" or "The gate is closed"  */
/* key is the id() of the key which will open the gate.       */
/* unlocked is set to 0 for locked 1 for unlocked             */
/* room_desc is the description of the room.  (to be sent to long_desc()) */
/* exit_to is the path to which the gate will lead.           */
inherit "/room/room";
string structure, gate, key, room_desc, exit_to;
int unlocked;
int i;
init(str) {
  ::init();
  i=0;
  unlocked=0;
  add_action("open","open");
  add_action("close","close");
  add_action("unlock","unlock");
  add_action("lock","lock");
  add_action("enter","enter");
}
int open(string str) {
  write(i+"\n");
  write(unlocked+" Open function A\n");
  i++;
  if(str=="gate") {
    if(gate=="The gate is open") {
      if(i != 2) {
         write(i+"\nIt's already open!\n");
         write(unlocked+" open function B\n");
      }
      else {
         write(i+"\nYou open the gate.\n");
         write(unlocked+" open function C\n");
      }
      i=0;
  write(i+"\n");
      write(unlocked+" open D\n");
      return 1;
      }
    if(gate=="The gate is closed") {
      if(unlocked==1) {
        gate="The gate is open";
        long_desc=room_desc+gate+".\n";
        write(i+"\n");
        write(unlocked+" open E\n");
        exit_to->open(str);
        i=0;
  write(i+"\n");
        write(unlocked+"open F\n");
        return 1;
        }
      if(unlocked==0) {
        write(i+"\nThe gate is locked.\n");
        write(unlocked+" open G\n");
        i=0;
  write(i+"\n");
        write(unlocked+" open H\n");
        return 1;
        }
      }
    }
  i=0;
  write(i+"\n");
  write(unlocked+" open I\n");
  return 0;
}
int unlock(string str) {
  write(i+"\n");
  write(unlocked+" unlock A\n");
  i++;
  if(str=="gate") {
    if(unlocked==1) {
      if(i != 2) {
         write(i+"\nIt's already unlocked!\n");
         write(unlocked+" unlock B\n");
      }
      else {
         write(i+"\nYou turn the key in the lock and hear a click.\n");
         write(unlocked+" unlock C\n");
      }
      i=0;
      write(i+"\n");
      return 1;
      }
    if(unlocked==0 && present(key,this_player())) {
      unlocked=1;
      exit_to->unlock(str);
      write(i+"\n");
      write(unlocked+" unlock D\n");
      i=0;
      write(i+"\n");
      return 1;
      }
    if(gate=="The gate is open") {
      write(i+"\nWhy do you want to unlock an open gate?\n");
      i=0;
      write(i+"\n");
      return 1;
      }
    if(unlocked==0 && !present(key,this_player())) {
      write("You don't seem to have the key to the gate.\n");
      i=0;
      write(i+"\n");
      return 1;
      }
  }
  i=0;
  write(i+"\n");
  return 0;
}
int close(string str) {
  write(i+"\n");
  i++;
  if(str=="gate") {
    if(gate=="The gate is closed") {
      if(i != 2) write(i+"\nThe gate is already closed!\n");
      else write(i+"\nYou close the gate.\n");
      i=0;
  write(i+"\n");
      return 1;
      }
    if(gate=="The gate is open") {
      if(unlocked==1) {
        gate="The gate is closed";
        long_desc=room_desc+gate+".\n";
        write(i+"\n");
        exit_to->close(str);
        i=0;
  write(i+"\n");
        return 1;
      }
      if(unlocked==0) {
        write("The deadbolt on the gate is in the locked position.\nYou cannot close the gate.\n");
        i=0;
  write(i+"\n");
        return 1;
      }
    }
  }
  i=0;
  write(i+"\n");
  return 0;
}
int lock(string str) {
  write(i+"\n");
  i++;
  if(str=="gate") {
    if(unlocked==0) {
      if(i != 2) write(i+"\nIt's already locked!\n");
      else write(i+"You lock the gate.\n");
      i=0;
  write(i+"\n");
      return 1;
      }
    if(unlocked==1 && present(key,this_player())) {
      unlocked=0;
      exit_to->lock(str);
      i=0;
  write(i+"\n");
      return 1;
      }
    if(unlocked==1 && !present(key,this_player())) {
      write("You don't seem to have the key to the gate.\n");
      i=0;
  write(i+"\n");
      return 1;
      }
  i=0;
  write(i+"\n");
  return 0;
  }
}
int enter(string str) {
  write(i+"\n");
  if(str=="gate" || str==structure) {
    if(gate=="The gate is open") {
      this_player()->move_player("through a gate#"+exit_to);
      return 1;
      }
    if(gate=="The gate is closed") {
      write(i+"How can you do that when the gate is closed?\n");
      return 1;
      }
    }
  return 0;
}
