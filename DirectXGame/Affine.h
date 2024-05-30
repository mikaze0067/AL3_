#pragma once
#include <Matrix4x4.h>
#include <Vector3.h>
#include <cmath>
#include <cassert>

//Matrix4x4 Multiply(Matrix4x4 matrix1, Matrix4x4 matrix2) {
//	Matrix4x4 result = {};
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			for (int k = 0; k < 4; k++) {
//				result.m[i][j] += matrix1.m[i][k] * matrix2.m[k][j];
//			}
//		}
//	}
//	return result;
//}

 //行列の掛け算
Matrix4x4 MatrixMultiply(Matrix4x4& m1, Matrix4x4& m2) {

	Matrix4x4 result;
	result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
	result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
	result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
	result.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];
	result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
	result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
	result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
	result.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];
	result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
	result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
	result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
	result.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];
	result.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
	result.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
	result.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
	result.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];

	return result;
}

//// 拡大縮小行列
//Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
//	Matrix4x4 ans = {0};
//	ans.m[0][0] = scale.x;
//	ans.m[1][1] = scale.y;
//	ans.m[2][2] = scale.z;
//	ans.m[3][3] = 1;
//	return ans;
//}
//
//// 平行移動行列
//Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
//	Matrix4x4 ans = {0};
//	ans.m[0][0] = 1;
//	ans.m[1][1] = 1;
//	ans.m[2][2] = 1;
//	ans.m[3][0] = translate.x;
//	ans.m[3][1] = translate.y;
//	ans.m[3][2] = translate.z;
//	ans.m[3][3] = 1;
//	return ans;
//}
//
//// X
//Matrix4x4 MakeRotateXMatrix(float radian) {
//	Matrix4x4 ans = {0};
//	ans.m[0][0] = 1;
//	ans.m[1][1] = cosf(radian);
//	ans.m[1][2] = sinf(radian);
//	ans.m[2][1] = -sinf(radian);
//	ans.m[2][2] = cosf(radian);
//	ans.m[3][3] = 1;
//	return ans;
//}
//// Y
//Matrix4x4 MakeRotateYMatrix(float radian) {
//	Matrix4x4 ans = {0};
//	ans.m[0][0] = cosf(radian);
//	ans.m[0][2] = -sinf(radian);
//	ans.m[1][1] = 1;
//	ans.m[2][0] = sinf(radian);
//	ans.m[2][2] = cosf(radian);
//	ans.m[3][3] = 1;
//	return ans;
//}
//// Z
//Matrix4x4 MakeRotateZMatrix(float radian) {
//	Matrix4x4 ans = {0};
//	ans.m[0][0] = cosf(radian);
//	ans.m[0][1] = sinf(radian);
//	ans.m[1][0] = -sinf(radian);
//	ans.m[1][1] = cosf(radian);
//	ans.m[2][2] = 1;
//	ans.m[3][3] = 1;
//	return ans;
//}
//
//// 3次元アフィン変換行列
//Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translation) {
//	Matrix4x4 ans;
//	ans = Multiply(Multiply(MakeScaleMatrix(scale), Multiply(Multiply(MakeRotateXMatrix(rotate.x), MakeRotateYMatrix(rotate.y)), MakeRotateZMatrix(rotate.z))), MakeTranslateMatrix(translation));
//	return ans;
//}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate) {

	Matrix4x4 ScallMat, RotateMat, RotateMatX, RotateMatY, RotateMatZ, TranslateMat, returnMat;

	// スケール行列作成
	ScallMat = {scale.x, 0, 0, 0, 0, scale.y, 0, 0, 0, 0, scale.z, 0, 0, 0, 0, 1};

	// XYZ回転行列作成
	RotateMatX = {1, 0, 0, 0, 0, cosf(rot.x), sinf(rot.x), 0, 0, -sinf(rot.x), cosf(rot.x), 0, 0, 0, 0, 1};

	RotateMatY = {cosf(rot.y), 0, -sinf(rot.y), 0, 0, 1, 0, 0, sinf(rot.y), 0, cosf(rot.y), 0, 0, 0, 0, 1};

	RotateMatZ = {cosf(rot.z), sinf(rot.z), 0, 0, -sinf(rot.z), cosf(rot.z), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

	// XYZ回転行列の合成(Z*X*Y)
	RotateMat = MatrixMultiply(RotateMatZ, RotateMatX);
	// ↑の結果＊Y軸回転
	RotateMat = MatrixMultiply(RotateMat, RotateMatY);

	// 平行移動行列作成
	TranslateMat = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, translate.x, translate.y, translate.z, 1};

	// スケール＊回転＊平行移動をワールド変換行列に
	returnMat = MatrixMultiply(ScallMat, RotateMat);
	returnMat = MatrixMultiply(returnMat, TranslateMat);

	return returnMat;
}
