silence(arg) {
  if(!arg) {
    if(!silent_move) {
      write("The movements of your Creatures will now be silent.\n");
      silent_move = 1;
      return 1;
    }
    write("The movements of your Creatures will now be evident.\n");
    silent_move = 0;
    return 1;
  }
  write("Syntax: silence\n");
  return 1;
}

