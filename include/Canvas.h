
#ifndef CANVAS_H
#define CANVAS_H


class Canvas {
    private:
    int** _Tab;
    int _rows,_cols;

    public:
        Canvas(int x, int y);

        ~Canvas();

        int getHeight();

        int getWidth();

        void Create();

        void fill(int value);

        void SetX(int x, int value);
                    /*
                   0**************x - cols
                    *     |  #   *
                    *     |  #   *
                    *     |  #   *
                    *-----+--#---*
                    *     |  #   *
                    *     |  #   *
            rows - y**************
                    */


        void SetY(int y, int value);

                /*
               0**************x
                *     |      *
                *############*
                *     |      *
                *-----+------*
                *     |      *
                *     |      *
               y**************
                */

        int Get(int x, int y);
        void Set(int x, int y, int value);



private:
    Canvas(const Canvas& c);
    Canvas& operator=(const Canvas& c);


};

#endif
