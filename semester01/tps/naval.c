//olá professor! o programa que segue foi refeito para evitar aquele meu hábito de substitiur "ifs" por "pows"
//deixei comentado no programa como o código original estava antes de trocá-lo
//realmente usar os ifs desde o início teria facilitado minha vida. muito obrigado!
#include <stdio.h>


//converts a char orientation input to a 0 or 1 (vertical->1 and horizontal->0)
int convert_orientation(char orientation_letter){
    if(orientation_letter=='V') return 1;
    else return 0;
}


//converts a char ship type to it's respective size
int convert_ship_type(char type_letter){
    if(type_letter=='C') return 3;
    else if(type_letter=='E') return 5;
    else return 7;
}


//converts the type hit to it's respective points
int point_conversion(char type_hit){
    if(type_hit=='C') return 2;
    else if(type_hit=='E') return 5;
    else if(type_hit=='P') return 10;
    else return 0;
}


//returns -1 if target placement won't cause out of index error
//else returns a new limit position (counting from where the placement should have originally started) for target in the board
int possible_board_placements(int board_rows, int board_columns, int target_x, int target_y, int target_size, int target_orientation){
    int output=0;

    if(target_orientation==0 && (target_x-(target_size-1)/2<0 || target_x+(target_size-1)/2>board_columns-1)){
        if(target_x<(target_size-1)/2) output += target_size-1;
        //output += (target_size-1)*(int)pow(0, (int)pow(2, target_x-(target_size-1)/2));
        if(board_columns-1<target_x+(target_size-1)/2) output += board_columns-target_size;
        //output += (board_columns-target_size)*(int)pow(0, (int)pow(2, board_columns-1-target_x-(target_size-1)/2));
    }
    else if(target_orientation==1 && (target_y-(target_size-1)/2<0 || target_y+(target_size-1)/2>board_rows-1)){
        if(target_y<(target_size-1)/2) output += target_size-1;
        //output += (target_size-1)*(int)pow(0, (int)pow(2, target_y-(target_size-1)/2));
        if(board_rows-1<target_y+(target_size-1)/2) output += board_rows-target_size;
        //output += (board_rows-target_size)*(int)pow(0, (int)pow(2, board_rows-1-target_y-(target_size-1)/2));
    }
    else{
        output = -1;
    }

    return output;
}


//main function
int main(){
    char board[2][20][20];
    //turn info
    int max_turns, turn_marker=0;
    int points[] = {0, 0};
    int attack_x, attack_y;
    //ship info
    int ship_number;
    int ship_x, ship_y, int_size, int_orientation;
    char ship_type, ship_orientation;
    int possible_placement;

    //creating both player boards
    for(int rows=0; rows<20; rows++){
        for(int columns=0; columns<20; columns++) board[0][rows][columns] = '~';
    }
    for(int rows=0; rows<20; rows++){
        for(int columns=0; columns<20; columns++) board[1][rows][columns] = '~';
    }

    //receiving ship inputs
    scanf("%d", &ship_number);
    for(int i=0; i<ship_number*2; i++){
        scanf("%d %d %c %c", &ship_y, &ship_x, &ship_type, &ship_orientation);

        //treating the inputs
        if(i>ship_number-1) turn_marker = 1;
        int_size = convert_ship_type(ship_type);
        int_orientation = convert_orientation(ship_orientation);
        possible_placement = possible_board_placements(20, 20, ship_x, ship_y, int_size, int_orientation);

        //placing ships if the placement wouldn't give index error
        if(possible_placement==-1){
            for(int position=ship_x*-(int_orientation-1)+ship_y*int_orientation-(int_size-1)/2; position<(int_size-1)/2+ship_x*-(int_orientation-1)+ship_y*int_orientation+1; position++){
                board[turn_marker][ship_y*-(int_orientation-1)+position*int_orientation][ship_x*int_orientation+position*-(int_orientation-1)] = ship_type;
            }
        }

        //placing ships if a index error would've occurred (the program snaps the ship to the closest board border)
        else{
            //for(int position=19*(int)pow(0, (int)pow(2, 10-possible_placement)); possible_placement-1*(int)pow(0, (int)pow(2, 10-possible_placement))+1*!(int)pow(0, (int)pow(2, 10-possible_placement))!=position; position+=-2*(int)pow(0, (int)pow(2, 10-possible_placement))+1){
            if(10<possible_placement){
                for(int position=19; possible_placement-1!=position; position--){
                    board[turn_marker][ship_y*-(int_orientation-1)+position*int_orientation][ship_x*int_orientation+position*-(int_orientation-1)] = ship_type;
                }
            }
            else{
                for(int position = 0; possible_placement+1!=position; position++){
                    board[turn_marker][ship_y*-(int_orientation-1)+position*int_orientation][ship_x*int_orientation+position*-(int_orientation-1)] = ship_type;
                }
            }
        }
    }

    //main game loop
    scanf("%d", &max_turns);
    turn_marker=0;
    for(int turns=0; turns<max_turns*2; turns++){
        scanf("%d %d", &attack_y, &attack_x);
        points[turn_marker]+=point_conversion(board[(turn_marker+1)%2][attack_y][attack_x]);
        board[(turn_marker+1)%2][attack_y][attack_x] = 'O';
        turn_marker = (turn_marker+1)%2;
    }

    //printing the end board
    printf("TABULEIRO JOGADOR 1\n");
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++) printf("%c ", board[0][i][j]);
        printf("\n");
    }
    printf("\nTABULEIRO JOGADOR 2\n");
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++) printf("%c ", board[1][i][j]);
        printf("\n");
    }

    //calculating winner
    if(points[0]==points[1]) printf("\nO jogo terminou empatado em %d pontos.", points[0]);
    else if(points[0]>points[1]) printf("\nO jogador 1 venceu com %d pontos, contra %d pontos do jogador 2.", points[0], points[1]);
    else printf("\nO jogador 2 venceu com %d pontos, contra %d pontos do jogador 1.", points[1], points[0]);
    //else printf("\nO jogador %d venceu com %d pontos, contra %d pontos do jogador %d.", 1+1*(int)pow(0, (int)pow(2, points[0]-points[1])), points[1*(int)pow(0, (int)pow(2, points[0]-points[1]))], points[1*(int)pow(0, (int)pow(2, -points[0]+points[1]))], 1+1*(int)pow(0, (int)pow(2, -points[0]+points[1])));

    //ending program
    return 0;
}