id(str) {
        return str == "sign";
        }

short() {
return "A large sign";
        }

long() {
write("The entrance to the dread maze Argannos lies ahead. Bid your loved\n");
write("ones farewell because the chances of you ever seeing them again\n");
write("after entering this archway are slim indeed. Only very few\n");
write("have found their way through this maze, only to be confronted by a\n");
write("greater evil. Think twice before entering Argannos!\n");
       }

reset(arg) {
  if (arg) return 1;
  return 1;
}

init() {
        add_action("read_sign","read");
}

read_sign(str) {
        if (!id(str)) return 0;
        long();
        return 1;
}
