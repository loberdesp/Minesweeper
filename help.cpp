help::help() {
    restart=1;
}

int help::getRestartState() {
    return restart;
}

void help::toggleRestart() {
    if(restart==1) {
        restart=0;
    } else {
        restart=1;
    }
}