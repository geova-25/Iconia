int* encuentre_vacio(){
    int i = 0;
    int j = 0;
    while(i != img.rows)
    {
        //cout << "i: " << i << endl;
        //cout << "j: " << j << endl;
        if(j == img.cols){
            j = 0;
            i += 1;
        }
        else if(verificar_desigualdad(i,j))
        {
            encuentre_cuadrado(i,j);
            return l1;
        }
        else{
            j += 1;
        }
    }
    cout << "¡No encontro nada!" << endl;
}
