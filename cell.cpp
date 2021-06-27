struct Cell
{
    bool alive;
    long long age;
    short int neighbours;
};

void compute_neighbours(Cell board[x_size][y_size], int x, int y)
{
                    board[x][y].neighbours = 0;
                    if (x==0) //left first line
                    {
                        if (y==0)
                        {
                            if (board[x+1][y].alive) board[x][y].neighbours++;
                            if (board[x+1][y+1].alive) board[x][y].neighbours++;
                            if (board[x][y+1].alive) board[x][y].neighbours++;
                            if (board[x_size-1][y_size-1].alive) board[x][y].neighbours++; //borderless
                        }
                        else if (y<y_size-1)
                        {
                            if (board[x][y-1].alive) board[x][y].neighbours++;
                            if (board[x+1][y-1].alive) board[x][y].neighbours++;
                            if (board[x+1][y].alive) board[x][y].neighbours++;
                            if (board[x+1][y+1].alive) board[x][y].neighbours++;
                            if (board[x][y+1].alive) board[x][y].neighbours++;
                            if (board[x_size-1][y-1].alive) board[x][y].neighbours++; //borderless
                            if (board[x_size-1][y].alive) board[x][y].neighbours++;
                            if (board[x_size-1][y+1].alive) board[x][y].neighbours++;
                        }
                        else if (y==y_size-1)
                        {
                            if (board[x][y-1].alive) board[x][y].neighbours++;
                            if (board[x+1][y-1].alive) board[x][y].neighbours++;
                            if (board[x+1][y].alive) board[x][y].neighbours++;
                            if (board[x_size-1][0].alive) board[x][y].neighbours++; //borderless
                        }
                    }
                    else if (x<x_size-1)
                    {
                        if (y==0)
                        {
                            if (board[x-1][y].alive) board[x][y].neighbours++;
                            if (board[x-1][y+1].alive) board[x][y].neighbours++;
                            if (board[x][y+1].alive) board[x][y].neighbours++;
                            if (board[x+1][y+1].alive) board[x][y].neighbours++;
                            if (board[x+1][y].alive) board[x][y].neighbours++;
                            if (board[x-1][y_size-1].alive) board[x][y].neighbours++; //borderless
                            if (board[x][y_size-1].alive) board[x][y].neighbours++;
                            if (board[x+1][y_size-1].alive) board[x][y].neighbours++;
                        }
                        else if (y<y_size-1)
                        {
                            if (board[x][y-1].alive) board[x][y].neighbours++;
                            if (board[x+1][y-1].alive) board[x][y].neighbours++;
                            if (board[x+1][y].alive) board[x][y].neighbours++;
                            if (board[x+1][y+1].alive) board[x][y].neighbours++;
                            if (board[x][y+1].alive) board[x][y].neighbours++;
                            if (board[x-1][y+1].alive) board[x][y].neighbours++;
                            if (board[x-1][y].alive) board[x][y].neighbours++;
                            if (board[x-1][y-1].alive) board[x][y].neighbours++;
                        }
                        else if (y==y_size-1)
                        {
                            if (board[x][y-1].alive) board[x][y].neighbours++;
                            if (board[x+1][y-1].alive) board[x][y].neighbours++;
                            if (board[x+1][y].alive) board[x][y].neighbours++;
                            if (board[x-1][y].alive) board[x][y].neighbours++;
                            if (board[x-1][y-1].alive ) board[x][y].neighbours++;
                            if (board[x-1][0].alive) board[x][y].neighbours++; //borderless
                            if (board[x][0].alive) board[x][y].neighbours++;
                            if (board[x+1][0].alive) board[x][y].neighbours++;
                        }
                    }
                    else if (x==x_size-1)
                    {
                        if (y==0)
                        {
                            if (board[x][y+1].alive) board[x][y].neighbours++;
                            if (board[x-1][y+1].alive) board[x][y].neighbours++;
                            if (board[x-1][y].alive) board[x][y].neighbours++;
                            if (board[0][y_size-1].alive) board[x][y].neighbours++; //borderless
                        }
                        else if (y<y_size-1)
                        {
                            if (board[x][y+1].alive) board[x][y].neighbours++;
                            if (board[x-1][y+1].alive) board[x][y].neighbours++;
                            if (board[x-1][y].alive) board[x][y].neighbours++;
                            if (board[x-1][y-1].alive) board[x][y].neighbours++;
                            if (board[x][y-1].alive) board[x][y].neighbours++;
                            if (board[0][y-1].alive) board[x][y].neighbours++; //borderless
                            if (board[0][y].alive) board[x][y].neighbours++;
                            if (board[0][y+1].alive) board[x][y].neighbours++;
                        }
                        else if (y==y_size-1)
                        {
                            if (board[x-1][y].alive) board[x][y].neighbours++;
                            if (board[x-1][y-1].alive) board[x][y].neighbours++;
                            if (board[x][y-1].alive) board[x][y].neighbours++;
                            if (board[0][0].alive) board[x][y].neighbours++;
                        }
                    }
};