inherit "room/room";
object spectre;
string name;

reset(arg) {
  if(!spectre) {
  spectre=clone_object("obj/monster");
  call_other(spectre, "set_name", "spectral priest");
