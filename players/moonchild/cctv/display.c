 /* #include "../std/list_nicely.h"

string *dests;
int current;

status id(string str) {
  return str=="picture" || str=="moving picture";
}

string short() {
  return "A strange picture, whose tones seem to melt into each other";
}

string query_plural() {
  return "strange pictures, whose tones seem to melt into each other";
}

void reset(int arg) {
  if(!arg)
    current=-1;
}

void set_dests(string *str) {
  dests=str;
}

int query_current() {
  return current==-1 ? 1000 : current/2;
}

void long() {
  write("This is a very strange picture, whose tones seem to melt into each other.\n");
  if(current!=-1)
    write("It is currently showing a picture of "
	+ capitalize(dests[current]));
  else
    write("It is currently not showing anything much");
  write(".\n\nTo spy on a location, type: spy <location>, to stop spying, ");
  write("type: spy.\n\nSelections are currently:\n\n");
  write(list_nicely(filter_array(dests, "even_filter", this_object())));
  write("\nIt is far too heavy for you to be able to pick it up.\n");
}

int even_filter(string str) {
  return !(member_array(str, dests)%2);
}
  
void init() {
  add_action("spy", "spy");
}

status spy(string str) {
  int tmp;
  if(!str) {
    write("The picture becomes static.\n");
    current=-1;
    return 1;
  }
  tmp=current;
  current=member_array(str, dests);
  if(current==-1) {
    write("Invalid choice.\n");
    return 1;
  }
  write("Ok.\n");
  return 1;
}
*/
