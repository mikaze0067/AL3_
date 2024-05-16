#pragma once
#include <Matrix4x4.h>
#include <Vector3.h>
#include <cmath>
#include <cassert>

Matrix4x4 MatrixMultiply(Matrix4x4 matrix1, Matrix4x4 matrix2) {
	Matrix4x4 result = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				result.m[i][j] += matrix1.m[i][k] * matrix2.m[k][j];
			}
		}
	}
	return result;
}

Matrix4x4 MakeTranslateMatrix(Vector3 translate) {
	Matrix4x4 ans;
	ans.m[0][0] = 1;
	ans.m[0][1] = 0;
	ans.m[0][2] = 0;
	ans.m[0][3] = 0;
	ans.m[1][0] = 0;
	ans.m[1][1] = 1;
	ans.m[1][2] = 0;
	ans.m[1][3] = 0;
	ans.m[2][0] = 0;
	ans.m[2][1] = 0;
	ans.m[2][2] = 1;
	ans.m[2][3] = 0;
	ans.m[3][0] = translate.x;
	ans.m[3][1] = translate.y;
	ans.m[3][2] = translate.z;
	ans.m[2][3] = 1;
	return ans;
}

Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 ans;
	ans.m[0][0] = scale.x;
	ans.m[0][1] = 0;
	ans.m[0][2] = 0;
	ans.m[0][3] = 0;
	ans.m[1][0] = 0;
	ans.m[1][1] = scale.y;
	ans.m[1][2] = 0;
	ans.m[1][3] = 0;
	ans.m[2][0] = 0;
	ans.m[2][1] = 0;
	ans.m[2][2] = scale.z;
	ans.m[2][3] = 0;
	ans.m[3][0] = 0;
	ans.m[3][1] = 0;
	ans.m[3][2] = 0;
	ans.m[3][3] = 1;
	return ans;
}

Vector3 TransForm(Vector3 v, Matrix4x4 matrix) {
	Vector3 resalt;
	resalt.x = v.x * matrix.m[0][0] + v.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	resalt.y = v.x * matrix.m[0][1] + v.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	resalt.z = v.x * matrix.m[0][2] + v.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	float w = v.x * matrix.m[0][3] + v.y * matrix.m[1][3] + 1.0f * matrix.m[2][3];
	assert(w != 0.0f);
	resalt.x /= w;
	resalt.y /= w;
	resalt.z /= w;
	return resalt;
}

Matrix4x4 RotateZMatrix(float theta) {
	Matrix4x4 ans;
	ans.m[0][0] = cosf(theta);
	ans.m[0][1] = sinf(theta);
	ans.m[0][2] = 0;
	ans.m[0][3] = 0;
	ans.m[1][0] = -sinf(theta);
	ans.m[1][1] = cosf(theta);
	ans.m[1][2] = 0;
	ans.m[1][3] = 0;
	ans.m[2][0] = 0;
	ans.m[2][1] = 0;
	ans.m[2][2] = 1;
	ans.m[2][3] = 0;
	ans.m[3][0] = 0;
	ans.m[3][1] = 0;
	ans.m[3][2] = 0;
	ans.m[3][3] = 1;
	return ans;
}

Matrix4x4 RotateXMatrix(float theta) {
	Matrix4x4 ans;
	ans.m[0][0] = 1;
	ans.m[0][1] = 0;
	ans.m[0][2] = 0;
	ans.m[0][3] = 0;
	ans.m[1][0] = 0;
	ans.m[1][1] = cosf(theta);
	ans.m[1][2] = sinf(theta);
	ans.m[1][3] = 0;
	ans.m[2][0] = 0;
	ans.m[2][1] = -sinf(theta);
	ans.m[2][2] = cosf(theta);
	ans.m[2][3] = 0;
	ans.m[3][0] = 0;
	ans.m[3][1] = 0;
	ans.m[3][2] = 0;
	ans.m[3][3] = 1;
	return ans;
}

Matrix4x4 RotateYMatrix(float theta) {
	Matrix4x4 ans;
	ans.m[0][0] = cosf(theta);
	ans.m[0][1] = 0;
	ans.m[0][2] = -sinf(theta);
	ans.m[0][3] = 0;
	ans.m[1][0] = 0;
	ans.m[1][1] = 1;
	ans.m[1][2] = 0;
	ans.m[1][3] = 0;
	ans.m[2][0] = sinf(theta);
	ans.m[2][1] = 0;
	ans.m[2][2] = cosf(theta);
	ans.m[2][3] = 0;
	ans.m[3][0] = 0;
	ans.m[3][1] = 0;
	ans.m[3][2] = 0;
	ans.m[3][3] = 1;
	return ans;
}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotation, const Vector3& translation) {
	Matrix4x4 ScaleMat, Rotate, RotateMatX, RotateMatY, RotateMatZ, TranslateMat, returnMat;

	/*ScaleMat = {scale.x, 0, 0, 0,
		        0, scale.y, 0, 0,
		        0, 0, scale.z, 0, 
		        0,   0,   0,   1};

	RotateMatX = { std::cosf(radian), std::sinf(theta), 0
};

	RotateMatY = {0, -std::sinf(theta), std::cos(theta)};

	RotateMatZ = {0,0,1};

	RotateMat = MatrixMultiply(RotateMatX, MatrixMultiply(RotateMatY, RotateMatZ));


	returnMat = MatrixMultiply(ScallMat, RotateMat);
	returnMat = MatrixMultiply(returnMat, TranslateMat);*/
}
