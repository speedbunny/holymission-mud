test(){
string x;

rm ("/players/./lila.o");
x = read_file("/players/./lila/lila.o");
write_file("/players/./lila.o",x);
}
