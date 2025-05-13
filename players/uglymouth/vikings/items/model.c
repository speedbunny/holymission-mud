/* a small scale model of the area shows where people are in it */
inherit "obj/thing";

void reset(int arg) {
  ::reset(arg);

  if(arg) return;
  set_name("small scale model of the viking area");
  set_alias("model");
  set_short("A small scale model of the viking area");
  set_long("This is a precisely made small scale model of Uglymouth's viking area.\n"
    + "If you 'spy' it carefully you can even see people walking in it.\n");
   }

void init() {
  ::init();
  add_action("spot_players","spy");
  }

int spot_players(string str) {
int i,j;
object *u;
string place,*placetest;
  if(!id(str)) return 0;
  u = users();
  for(i=0;i<sizeof(u);i++) {
    place = file_name(environment(u[i]));
    placetest = explode(place,"/");
    if(placetest[1] == "uglymouth" && placetest[2] == "vikings") {
      write(capitalize(u[i]->query_real_name()) + " is at " + placetest[3] + "\n");
      j++;
      }
    }
  if(j==1) write("There is " + j + " player in the viking area.\n");
  else write("There are " + j + " players in the viking area.\n");
  return 1;
  }
