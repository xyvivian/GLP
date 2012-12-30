//
//  SLModel.h
//  GLP
//
//  Created by Zheng Shao on 12/28/12.
//  Copyright (c) 2012 Saigo Laboratoire. All rights reserved.
//
//  Created by Zheng Shao on 12/20/12.
//  Copyright (c) 2012 Saigo Laboratoire. All rights reserved.
//
//  This is free software with ABSOLUTELY NO WARRANTY.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//  02111-1307, USA
//

#ifndef __GLP__SLModel__
#define __GLP__SLModel__

#include <iostream>
#include <Eigen/Core>
#include "SLModelStrategy.h"

using namespace Eigen;

// the Context of strategy pattern
template <typename AStrategy>
class SLModel
{
public:
    map<SLTRAINRESULTYPE, MatrixXd> getTrainResult(SLTRAINRESULTYPE type)   { return aStrategy.getTrainResult(type); }
    bool train   (MatrixXd& X, MatrixXd& Y, MatrixXd** Beta)                { return aStrategy.train(X, Y, Beta); }
    bool validate(MatrixXd& X, MatrixXd& Y, MatrixXd& Beta)                 { return aStrategy.validate(X, Y, Beta); }
    bool classify(MatrixXd& X, MatrixXd& Y, MatrixXd& Beta)                 { return aStrategy.classify(X, Y, Beta); }
    
    template <typename MP>
    bool initParameters(MP modelParameters) { return aStrategy.initParameters(modelParameters); }
    
private:
    AStrategy aStrategy;
};

#endif /* defined(__GLP__SLModel__) */
