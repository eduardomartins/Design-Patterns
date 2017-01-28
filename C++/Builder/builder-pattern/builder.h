/*
 * builder.h
 *
 * Copyright 2017 Eduardo Sant' Anna Martins <eduardo@eduardomartins.site>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>
#include <memory>

using namespace std;

typedef enum {
        JPEG = 0,
        BMP,
        PNG,

} compressionType;

const string types[] = {
 "JPEG",
 "BMP",
 "PNG",
};


// ------------------ Product Class --------------------

class Image
{
public:

    void open(const string &path){
        setPath(path);
    }

    void setSize(int x, int y){
        if(x > 0 && y > 0){
            m_x = x;
            m_y = y;
        } else {
            cout << "Error value x and y must greather than 0";
        }
    }

    void setCompression(compressionType type){
        m_type = type;
    }

    compressionType type(void){
        return m_type;
    }


    void setPath(string path){
        m_path = path;
    }

    string path(){
        return m_path;
    }

    int x(void) {
        return m_x;
    }

    int y(void) {
        return m_y;
    }

private:
    int m_x;
    int m_y;
    string m_path;
    compressionType m_type;
};

// --------------------- Builder Class ---------------------


class CompressionBuilder {
public:

    CompressionBuilder(){
        m_image = new Image;
    }

    Image *image(){
        return m_image;
    }

    void createNewImage(){
        m_image = new Image;
    }

    virtual void convert() = 0;

    Image * m_image;
};

// ------------------ Concrete Builder ------------------
class CompressionJPEG: public CompressionBuilder {
public:
    void convert() {
        m_image->setCompression(JPEG);
        // converting algorithm here...
    }
};

class CompressionBMP: public CompressionBuilder {
public:
    void convert() {
        m_image->setCompression(BMP);
        // converting algorithm here...
    }
};

class CompressionPNG: public CompressionBuilder {
public:
    void convert() {
        m_image->setCompression(PNG);
        // converting algorithm here...
    }
};


// ----------------- Director class ---------------
class Convert{
public:
    void setSize(int x, int y){
        m_x = x;
        m_y = y;
    }

    void make(CompressionBuilder *cb){
        m_compressionBuilder = cb;
        m_compressionBuilder->createNewImage();
        m_compressionBuilder->image()->setSize(m_x, m_y);
        m_compressionBuilder->convert();
    }

    void result(){
        cout << "Converting to " << types[m_compressionBuilder->image()->type()] << endl;
    }

private:
    int m_x;
    int m_y;
    CompressionBuilder *m_compressionBuilder;
};

#endif // BUILDER_H
