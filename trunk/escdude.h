/****************************************************************************
** Copyright (c) 2012 Sebastian Schmitt
** All right reserved.
** Web: http://code.google.com/p/esc-tool-for-blheli/
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
** LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
** OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
** WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
****************************************************************************/

#ifndef ESCDUDE_H
#define ESCDUDE_H

#include <QWidget>

#include <QList>
#include "ceepromdefinitonfileparser.h"
#include "common.h"

class CProgrammer;
class CEscConf;
class CConfigModel;
class CEditorDelegate;

namespace Ui {
  class escdude;
}

class escdude : public QWidget
{
  Q_OBJECT
  
public:
  explicit escdude(QWidget *parent = 0);
  ~escdude();
  
private:
  Ui::escdude *ui;

  CProgrammer * c_pProgrammer;
  CEscConf * c_pConfig;
  CConfigModel * c_pConfigModel;
  CEditorDelegate * c_pEditorDelegate;

  QList<esc::SEEpromData*> c_configList;

private slots:
  void slot_chooseHexFile();
  void slot_writeFlash();
  void slot_verifyFlash();
  void slot_readConfig();
  void slot_writeConfig();
  void slot_dumpString(QString qsMessage);
};

#endif // ESCDUDE_H
