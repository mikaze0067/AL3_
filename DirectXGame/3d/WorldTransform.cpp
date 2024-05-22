#include "WorldTransform.h"
#include <Affine.h>

//#include "myMath.h"

void WorldTransform::UpdateMatrix() {
	//
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);
	//
	TransferMatrix();
}