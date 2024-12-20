#include <iostream>
#include <vector>
#include <memory>
#include <math.h>

using namespace std;


class Ponto {
    private:
    
        float x;
        float y;

    public:

        Ponto(){
            this->x = 0;
            this->y = 0;
        }
        Ponto(float x, float y){
            this->x = x;
            this->y = y;
        }

        void SetCoordinates(float x, float y){
            this->x = x;
            this->y = y;
        }
        vector<float> GetCoordinates(){
            vector<float> coordinates;
            coordinates.push_back(this->x);
            coordinates.push_back(this->y);
            return coordinates;
        }
};


class FiguraGeometrica {
    private:

        Ponto centro;

    public:

        FiguraGeometrica(){
            this->centro.SetCoordinates(0, 0);
        }
        FiguraGeometrica(float x, float y){
            this->centro.SetCoordinates(x, y);
        }
        virtual ~FiguraGeometrica(){}

        virtual void Desenha(){
            vector<float> coordinates = centro.GetCoordinates();
            cout << coordinates[0] << " " << coordinates[1];
        }
        virtual float CalculaArea() = 0;
};

class Retangulo : public FiguraGeometrica{
    private:

        double lado1;
        double lado2;

    public:

        Retangulo(){
            this->lado1 = 0;
            this->lado2 = 0;
        }
        Retangulo(double l1, double l2, float x, float y) : FiguraGeometrica(x, y){
            this->lado1 = l1;
            this->lado2 = l2;
        }

        void Desenha() override{
            FiguraGeometrica::Desenha();
            cout << " " << "RETANGULO" << endl;
        }
        float CalculaArea() override{
            return this->lado1 * this->lado2;
        }
};

class Circulo : public FiguraGeometrica{
    private:

        double raio;
    
    public:

        Circulo(){
            this->raio = 0;
        }
        Circulo(double r, float x, float y) : FiguraGeometrica(x, y){
            this->raio = r;
        }

        void Desenha() override{
            FiguraGeometrica::Desenha();
            cout << " " << "CIRCULO" << endl;
        }
        float CalculaArea() override{
            return this->raio * this->raio * M_PI;
        }
};

class Triangulo : public FiguraGeometrica{
    private:

        double altura;
        double base;

    public:

        Triangulo(){
            this->altura = 0;
            this->base = 0;
        }
        Triangulo(double h, double b, float x, float y) : FiguraGeometrica(x, y){
            this->altura = h;
            this->base = b;
        }

        void Desenha() override{
            FiguraGeometrica::Desenha();
            cout << " " << "TRIANGULO" << endl;
        }
        float CalculaArea() override{
            return this->altura * this->base / 2;
        }
};


int main(){
    bool runtime = true;
    char char_buffer;

    vector<FiguraGeometrica*> figuras;
    while(runtime){
        cin >> char_buffer;

        if(char_buffer == 'R'){
            float c1, c2;
            double l1, l2;
            cin >> c1 >> c2 >> l1 >> l2;
            figuras.push_back(new Retangulo(l1, l2, c1, c2));
        }
        if(char_buffer == 'C'){
            float c1, c2;
            double r;
            cin >> c1 >> c2 >> r;
            figuras.push_back(new Circulo(r, c1, c2));
        }
        if(char_buffer == 'T'){
            float c1, c2;
            double b, h;
            cin >> c1 >> c2 >> b >> h;
            figuras.push_back(new Triangulo(h, b, c1, c2));
        }
        if(char_buffer == 'D'){
            for(unsigned int i=0; i<figuras.size(); i++){
                figuras[i]->Desenha();
            }
        }
        if(char_buffer == 'A'){
            float total_area = 0;
            for(unsigned int i=0; i<figuras.size(); i++){
                total_area+=figuras[i]->CalculaArea();
            }
            printf("%.2f\n", total_area);
        }
        if(char_buffer == 'E'){
            runtime = false;
        }
    }

    for(unsigned int i=0; i<figuras.size(); i++){
        delete figuras[i];
    }

    return 0;
};