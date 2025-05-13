// Virtual area master.				Written by Sauron, 220897.

#include "/players/sauron/include/virtual.h"
#include "/players/sauron/include/virtual_functions.c"

#define PARSE_LIMIT		60

private string master;		// The file_name of this master object.

private int max_x;		// Maximum x dimension (width of the area).
private int max_y;		// Maximum y dimension (depth of the area).
private int max_z;		// Maximum z dimension (height of the area).

private mapping border_rooms;	// Connections to the outside world.
private mapping virtual_rooms;	// Connections within the area.
private mapping maps;		// Store the maps for each level of the area.
private mapping map_keys;	// Store the keys for the maps.

// Prototyping:

void init_border_room(int *coords);
void init_virtual_room(int *coords);
int valid_room(int *coords);
int *valid_exits(int *coords);
object clone_room(int *coords);
static void setup_border_exits(int *coords);
static void setup_virtual_exit(int *coords_a,int a_to_b);
void initialise_exits(int *coords);
static void parse_map2(string *arr,int z,int start);
static void parse_map(int z);
void set_area_size(int x,int y,int z);
void set_map(int z,string map);
void set_map_key(string key,string file);
void set_border_room(int *coords,string dir_to_border,string file);
void reset(int arg);
void init();

// End prototyping.

// Initialise the border rooms mapping.

void init_border_room(int *coords) {
  string tmp;
  int i;

  if(!border_rooms)
    border_rooms=([]);
  tmp=encode_coords(coords);
  if(!border_rooms[tmp]) {
    border_rooms[tmp]=allocate(B_SIZE);
    for(i=0;i<B_SIZE;i++)
      border_rooms[tmp][i]=({});
  }
}

// Initialise the virtual rooms mapping.

void init_virtual_room(int *coords) {
  string tmp;

  if(!virtual_rooms)
    virtual_rooms=([]);
  tmp=encode_coords(coords);
  if(!virtual_rooms[tmp]) {
    virtual_rooms[tmp]=allocate(V_SIZE);
    virtual_rooms[tmp][EXITS]=([]);
  }
}

// Is the room given valid? Returns 1 for yes, 0 for no.

int valid_room(int *coords) {
  if(coords[0]<0 || coords[0]>max_x-1)
    return 0;
  else if(coords[1]<0 || coords[1]>max_y-1)
    return 0;
  else if(coords[2]<0 || coords[2]>max_z-1)
    return 0;
  else
    return 1;
}

// Create an array of all the valid exits from a room, determined using
// valid_room():

int *valid_exits(int *coords) {
  int i,*tmp,*ret;

  ret=({});
  for(i=1;i<=10;i++) {
    tmp=exit_coords(coords,i);
    if(valid_room(tmp))
      ret+=({i});
    continue;
  }
  return ret;
}

object clone_room(int *coords) {
  string file,*arr;
  int i;
  object ob;
  mixed *tmp;

  tmp=virtual_rooms[encode_coords(coords)];
  if(tmp[ROOM])
    return tmp[ROOM];
  else
    file=map_keys[tmp[MAP_KEY]];
  if(file && file_size(file+".c")>0) {
    catch(file->a_load_fun());
    if(find_object(file)) {
      ob=clone_object(file);
      ob->set_virtual_coords(coords);
      arr=m_indices(tmp[EXITS]);
      for(i=0;i<sizeof(arr);i++) {
        if(stringp(tmp[EXITS][arr[i]]))
          ob->add_exit(arr[i],tmp[EXITS][arr[i]]);
        else
          ob->add_exit(arr[i],master+","+encode_coords(tmp[EXITS][arr[i]]));
      }
      ob->setup_room();
      virtual_rooms[encode_coords(coords)][ROOM]=ob;
      return ob;
    }
  }
}

// Set up an exit to any border room set for these coords:

static void setup_border_exits(int *coords) {
  string str;
  int i;
  mapping exits;
  mixed *tmp;

  str=encode_coords(coords);
  tmp=border_rooms[str];
  if(tmp) {
    exits=virtual_rooms[str][EXITS];
    if(!exits)
      exits=([]);
    for(i=0;i<sizeof(tmp[0]);i++)
      exits[tmp[EXITS][i]]=tmp[ROOM][i];
    virtual_rooms[str][EXITS]=exits;
  }
}

// Set up an exit between two virtual rooms:

static void setup_virtual_exit(int *coords_a,int a_to_b) {
  string tmpa,tmpb;
  int *coords_b;
  mapping exits_a,exits_b;

  coords_b=exit_coords(coords_a,a_to_b);
  tmpa=encode_coords(coords_a);
  tmpb=encode_coords(coords_b);
  if(virtual_rooms[tmpa])
    exits_a=virtual_rooms[tmpa][EXITS];
  if(virtual_rooms[tmpb])
    exits_b=virtual_rooms[tmpb][EXITS];

  if(!exits_a || !exits_b)
    return;

  else if(member(exits_a,name_dir(a_to_b)) ||
          member(exits_b,name_dir(reverse_dir(a_to_b))))
    return;

  else {
    exits_a[name_dir(a_to_b)]=coords_b;
    exits_b[name_dir(reverse_dir(a_to_b))]=coords_a;

    virtual_rooms[tmpa][EXITS]=exits_a;
    virtual_rooms[tmpb][EXITS]=exits_b;
  }
}

// Set up the exits in the virtual area:

void initialise_exits(int *coords) {
  string tmp;
  int i,j,*poss;

  tmp=encode_coords(coords);
  poss=valid_exits(coords);
  for(i=0;i<sizeof(poss);i++)
    setup_virtual_exit(coords,poss[i]);
  setup_border_exits(coords);
}

// Parse a level of the area from it's map:

static void parse_map2(string *arr,int z,int start) {
  string str;
  int i,x,y,end;

  if(sizeof(arr)>start+PARSE_LIMIT)
    end=start+PARSE_LIMIT;
  else
    end=sizeof(arr);
  for(i=start;i<end;i++) {
    if(arr[i]!=" ") {
      y=i/max_x;
      x=i-(y*max_x);

      str=encode_coords(({x,y,z}));
      init_virtual_room(({x,y,z}));
      virtual_rooms[str][MAP_KEY]=arr[i];
//      call_out("initialise_exits",0,({x,y,z}));
    }
  }
}

static void parse_map(int z) {
  string *arr;
  int start;

  if(maps[z])
    arr=explode(maps[z],"");
  if(!arr || !sizeof(arr))
    return;

  while(start<sizeof(arr)) {
    call_out("parse_map2",0,arr,z,start);
    start+=PARSE_LIMIT;
  }
}

// Set the dimensions of the virtual area:

void set_area_size(int x,int y,int z) {
  max_x=x;
  max_y=y;
  max_z=z;
}

// Set the map for a level of the area:

void set_map(int z,string map) {
  if(!maps)
    maps=([]);

  if(!max_x || !max_y || !max_z)
    return;

  else if(z<0 || z>max_z-1)
    return;

  else if(strlen(map)!=max_x*max_y)
    return;

  maps[z]=map;
  parse_map(z);
}

void set_map_key(string key,string file) {
  if(!map_keys)
    map_keys=([]);

  if(strlen(key)!=1 || key==" ")
    return;
  else if(file_size(file+".c")<0)
    return;
  else
    map_keys[key]=file;
}

// Set a border room for the vitual area:

void set_border_room(int *coords,string dir_to_border,string file) {
  string tmp;

  init_border_room(coords);
  tmp=encode_coords(coords);

  border_rooms[tmp][ROOM]+=({file});
  border_rooms[tmp][EXITS]+=({dir_to_border});
}

int test_coord(string str) {
  string *arr;
  int i,x,y,z;
  mixed *tmp;

  if(!str || sscanf(str,"%d,%d,%d",x,y,z)!=3)
    return 0;

  if((tmp=border_rooms[str])) {
    printf("Found border room information for location %s:\n",str);
    for(i=0;i<sizeof(tmp[0]);i++)
      printf("File: %s, dir: %s\n\n",tmp[ROOM][i],tmp[EXITS][i]);
  }
  if((tmp=virtual_rooms[str])) {
    printf("Found virtual room information for location %s:\n",str);
    if(tmp[ROOM])
      printf("Room object: %O\n",tmp[ROOM]);
    printf("Type: %s, file: %s\nExits: '",
           tmp[MAP_KEY],map_keys[tmp[MAP_KEY]]);
    arr=m_indices(tmp[EXITS]);
    for(i=0;i<sizeof(arr);i++) {
      printf("%s: %s",arr[i],
             (stringp(tmp[EXITS][arr[i]])?
               tmp[EXITS][arr[i]]:
               encode_coords(tmp[EXITS][arr[i]])));
      if(i<sizeof(arr)-1)
        write(", ");
    }
    write("'\n");
  }
  return 1;
}

void reset(int arg) {
  if(!arg) {
    master="/"+file_name(this_object());
    if(!border_rooms)
      border_rooms=([]);
    if(!virtual_rooms)
      virtual_rooms=([]);
  }
}

void init() {
  add_action("test_coord","test");
  printf("# of virtual rooms: %d\n# of border rooms: %d\n",
         m_sizeof(virtual_rooms),m_sizeof(border_rooms));
}
