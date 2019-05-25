
void createTexture(const Bitmap& bitmap, GLint minMagFiler, GLint wrapMode) :
    _originalWidth((GLfloat)bitmap.width()),
    _originalHeight((GLfloat)bitmap.height())
{
    glGenTextures(1, &_object);
    glBindTexture(GL_TEXTURE_2D, _object);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minMagFiler);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, minMagFiler);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
    glTexImage2D(GL_TEXTURE_2D,
                 0, 
                 TextureFormatForBitmapFormat(bitmap.format()),
                 (GLsizei)bitmap.width(), 
                 (GLsizei)bitmap.height(),
                 0, 
                 TextureFormatForBitmapFormat(bitmap.format()), 
                 GL_UNSIGNED_BYTE, 
                 bitmap.pixelBuffer());
    glBindTexture(GL_TEXTURE_2D, 0);
}

bool uploadAndRemoveSurface(SDL_Surface* surface)
{
    // Check if surface is valid

    bool status = false;
    status = true;






    
    return status;
}

int LoadGLTextures( )
{
    /* Status indicator */
    int Status = FALSE;

    glGenTextures( 1, &surface );
    glBindTexture( GL_TEXTURE_2D, surface );
    glTexImage2D( GL_TEXTURE_2D, 0, 3, TextureImage[0]->w,
            TextureImage[0]->h, 0, GL_RGB,
            GL_UNSIGNED_BYTE, TextureImage[0]->pixels );
    glGetError();
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    }
    
    SDL_FreeSurface( TextureImage[0] );

    return Status;
}