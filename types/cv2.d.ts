
export type External = Object;

export interface Mat {
    data: External, rows: number, cols: number, type: number
}

export function multiplyByTwo(value: number): number;
// export function allocateMat(rows: number, cols: number, type?: number): Buffer;
export function allocateMat(rows: number, cols: number, type?: number): Mat;
export function imread(filename: string): Mat;