/*  recorsive ile aritmetik ort bulma*/
int rec(int array[],int boyut,int toplam, int i,int sonuc){
if (boyut>i) {
  return toplam+rec(array,4,toplam,i+1,0);
}
else
  return 0;

}
int main(int argc, char const *argv[]) {
int i,array[10];

  for (i = 0; i < 4; i++) {
  scanf("%d",&array[i]);
  }
  printf("%d\n",rec(array,4,0,0,0));

  return 0;
}
