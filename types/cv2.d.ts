
export type External = Object;

export function multiplyByTwo(value: number): number;
// export function allocateMat(rows: number, cols: number, type?: number): Buffer;
export function allocateMat(rows: number, cols: number, type?: number): { data: External, rows: number, cols: number, type: number };
