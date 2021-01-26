#include<stdio.h>
#include<stdlib.h>

typedef struct images{
    int height, width;
    int **pixels;
}images_t;

images_t *create_image();
void read_image(images_t*);
images_t *input_padding(images_t*, int);
void print_image(images_t*);
void erase_image(images_t*);

int main(void){
    int height, width, padding;
    scanf("%d %d", &width, &height);
    images_t *original_image = create_image(height, width);
    read_image(original_image);
    scanf("%d", &padding);
    images_t *padding_image = input_padding(original_image, padding);
    print_image(padding_image);
    printf("\n");
    print_image(original_image);
    erase_image(original_image);
    erase_image(padding_image);
    return 0;
}

images_t *create_image(int height, int width){
    images_t *img = (images_t*)malloc(sizeof(images_t));
    img->height = height;
    img->width = width;
    img->pixels = (int**)calloc(height, sizeof(int*));
    for(int i = 0; i < height; i++){
        img->pixels[i] = (int*)calloc(width, sizeof(int));
    }
    return img;
}

void read_image(images_t *img){
    for(int i = 0; i < img->height; i++){
        for(int j = 0; j < img->width; j++){
            scanf("%d", &img->pixels[i][j]);
        }
    }
}

images_t *input_padding(images_t *img, int padding){
    int double_padding = padding * 2;
    images_t *img_padding = create_image(double_padding + img->height, double_padding + img->width);
    for(int i = 0; i < img->height; i++){
        for(int j = 0; j < img->width; j++){
            img_padding->pixels[i + padding][j + padding] = img->pixels[i][j];
        }
    }
    return img_padding;
}

void erase_image(images_t *image){
    for(int i = 0; i < image->height; i++){
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void print_image(images_t *img){
    // printf("h: %d w: %d\n", img->height, img->width);
    for(int i = 0; i < img->height; i++){
        for(int j = 0; j < img->width; j++){
            printf("%d ", img->pixels[i][j]);
        }
        printf("\n");
    }
}